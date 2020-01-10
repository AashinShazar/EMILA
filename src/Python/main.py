
from  PyQt5.QtWidgets  import * 
from  PyQt5.uic  import  loadUi
from PyQt5 import QtCore
from matplotlib import pyplot as plt
import time
import serial
import re
import numpy
from  matplotlib.backends.backend_qt5agg  import  ( NavigationToolbar2QT  as  NavigationToolbar )
import  numpy  as  np 
import  random
import pyqtgraph as pg
from pyqtgraph import PlotWidget, plot
from typing import *
import sys
import os
from matplotlib.backends.qt_compat import QtCore, QtWidgets
from matplotlib.backends.backend_qt5agg import FigureCanvas
import matplotlib.pyplot as mpl
import numpy as np
import serial
import numpy
import matplotlib.pyplot as plt
import re
import time
import os
from sklearn.datasets import load_files       
from keras.utils import np_utils
import numpy as np
from glob import glob
from keras.preprocessing import image                  
from tqdm import tqdm
from PIL import ImageFile        
from sklearn.metrics import f1_score
import pandas as pd
from keras.models import load_model
from PIL import Image
import matplotlib.image as mpimg
import os, shutil

minTrigger = 0.80

def path_to_tensor(img_path):
    # loads RGB image as PIL.Image.Image type
    img = image.load_img(img_path, target_size=(224, 224))
    # convert PIL.Image.Image type to 3D tensor with shape (224, 224, 3)
    x = image.img_to_array(img)
    # convert 3D tensor to 4D tensor with shape (1, 224, 224, 3) and return 4D tensor
    return np.expand_dims(x, axis=0)

def paths_to_tensor(img_paths):
    list_of_tensors = [path_to_tensor(img_path) for img_path in tqdm(img_paths)]
    return np.vstack(list_of_tensors)               

bigPath = 'C:\\Users\\aashi\\OneDrive\\Desktop\\school\\SFSU\\semester4 F19\\ENGR 478\\EMILA-CODE\\MachineLearning\\'

# define function to load train, test, and validation datasets
def load_dataset(path):
    data = load_files(path)
    print (data)
    part_files = np.array(sorted(glob("data/*")))
    return part_files

class  MatplotlibWidget ( QMainWindow ):
    
    def  __init__ ( self ):
        QMainWindow . __init__ ( self )
        loadUi ( "qt_designer.ui" , self )
        self . setWindowTitle ( "Project EMILA" )
        self . liveButton . clicked . connect ( self . live_emg )
        self . demoButton . clicked . connect ( self . demo_emg )
        self . spideyButton . clicked . connect ( self . gesture_spidey )
        self . relaxButton . clicked . connect ( self . gesture_relax )
        self . clenchButton . clicked . connect ( self . gesture_clench )

    def demo_emg(self):
        yLength = 50
        mlTime = 0
        current_time = time.strftime("%H%M%S", time.localtime())
        ser = serial.Serial('COM7', 9600, stopbits=1)
        plt.axis([0, yLength, 0, 5000])
        hl, = plt.plot([], [])
        plt.ylabel('EMG Signal (mV)')
        plt.xlabel('Time (0.1s)')

        self.textBrowser.append("Opening ML sample window...")

        ser.write('s'.encode('utf-8'))

        while True:
            dataOut = ser.readline()
            if ((dataOut.decode("utf-8")) == "INTERRUPT\r\n"):
                mlFile = "data/{0}".format(current_time)
                plt.savefig(mlFile)
                plt.clf()
                self.textBrowser.append("ML sample collected!")
                break
            else:
                try: 
                    dataIn = (re.findall('\d+', dataOut.decode("utf-8") ))[0]
                except:
                    dataIn = 0
                print(int(dataIn))
                hl.set_xdata(numpy.append(hl.get_xdata(), mlTime))
                hl.set_ydata(numpy.append(hl.get_ydata(), int(dataIn)))
                plt.pause(.01)
                mlTime = mlTime + 1

        self.textBrowser.append("Starting ML prediction...")
        # load train, test, and validation datasets
        unseen_files = load_dataset('data/')

        self.textBrowser.append('There are %d unseen part images.' % len(unseen_files))
        # pre-process the data for Keras
        ImageFile.LOAD_TRUNCATED_IMAGES = True  
        unseen_tensors = paths_to_tensor(unseen_files).astype('float32')/255

        model = load_model(bigPath + "vgg16_frozen.hdf5")

        # get index of predicted part for each image in the test image set
        part_predictions = [(model.predict(np.expand_dims(tensor, axis=0))) for tensor in unseen_tensors]
        print (part_predictions)

        for x in range (0, len(unseen_files)): 
            fileLocToBe = ""
            if ((part_predictions[x])[0])[1] > minTrigger and ((part_predictions[x])[0])[1] > ((part_predictions[x])[0])[0]:
                self.textBrowser.append("Spidey recognized!")
                print("Spidey recognized!")
                ser.write('b'.encode('utf-8')) #spidey
                ser.write('b'.encode('utf-8'))
                time.sleep(1)
                ser.write('n'.encode('utf-8'))

            elif ((part_predictions[x])[0])[0] > minTrigger and ((part_predictions[x])[0])[0] > ((part_predictions[x])[0])[1]:
                self.textBrowser.append("Clench recognized!")
                print("Clench recognized!")
                ser.write('a'.encode('utf-8')) #clench
                ser.write('a'.encode('utf-8')) #clench

                time.sleep(1)
                ser.write('n'.encode('utf-8'))

            else:
                self.textBrowser.append("gesture not recognized?")
                
                time.sleep(1)
                ser.write('n'.encode('utf-8'))

            try:
                os.mkdir(fileLocToBe)
            except:
                pass
            
            folder = 'data'
            for filename in os.listdir(folder):
                file_path = os.path.join(folder, filename)
                try:
                    if os.path.isfile(file_path) or os.path.islink(file_path):
                        os.unlink(file_path)
                    elif os.path.isdir(file_path):
                        shutil.move(file_path, bigPath+fileLocToBe)
                        shutil.rmtree(file_path)
                except Exception as e:
                    self.textBrowser.append('Failed to move %s. Reason: %s' % (file_path, e))

        sys.exit()
                
    def live_emg(self):
        
        self.progressBar.setValue(0)

        i = 0
        yLength = 50
        current_time = time.strftime("%H%M%S", time.localtime())
        plt.axis([0, yLength, 0, 5000])
        hl, = plt.plot([], [])
        plt.ylabel('EMG Signal (mV)')
        plt.xlabel('Time (0.1s)')

        ser = serial.Serial('COM7', 9600, stopbits=1)
        ser.write('s'.encode('utf-8'))
        
        while True:
            dataOut = ser.readline()
            print(dataOut.decode("utf-8"))

            if ((dataOut.decode("utf-8")) == "INTERRUPT\r\n"):
                ser.close()
                break
            else:
                try: 
                    dataIn = (re.findall('\d+', dataOut.decode("utf-8") ))[0]
                except:
                    dataIn = 0
                print(int(dataIn))
                hl.set_xdata(numpy.append(hl.get_xdata(), i))
                hl.set_ydata(numpy.append(hl.get_ydata(), int(dataIn)))
                plt.pause(.01)
                i = i + 1

        self.progressBar.setValue(100)
        plt.waitforbuttonpress()
        plt.close()

        sys.exit()

    def  gesture_relax ( self ):
        self.progressBar.setValue(0)

        ser = serial.Serial('COM7', 9600, stopbits=1)

        self.textBrowser.append("Resetting to neutral...")
        ser.write('n'.encode('utf-8'))
        self.textBrowser.append("Reset!")

        ser.close()
        self.progressBar.setValue(100)

    def  gesture_clench ( self ):
        self.progressBar.setValue(0)
        
        ser = serial.Serial('COM7', 9600, stopbits=1)

        self.textBrowser.append("Resetting to neutral before cycling...")
        ser.write('n'.encode('utf-8'))
        self.textBrowser.append("Reset!")
        time.sleep(1)

        self.textBrowser.append("Clench...")
        ser.write('a'.encode('utf-8'))
        ser.write('a'.encode('utf-8'))
        self.textBrowser.append("Clenched!")
        time.sleep(1)

        self.textBrowser.append("Resetting to neutral...")
        ser.write('n'.encode('utf-8'))
        self.textBrowser.append("Reset!")
        
        ser.close()
        self.progressBar.setValue(100)

    def  gesture_spidey ( self ):
        self.progressBar.setValue(0)

        ser = serial.Serial('COM7', 9600, stopbits=1)

        self.textBrowser.append("Resetting to neutral before cycling...")
        ser.write('n'.encode('utf-8'))
        self.textBrowser.append("Reset!")
        time.sleep(1)

        self.textBrowser.append("Spidey...")
        ser.write('b'.encode('utf-8'))
        ser.write('b'.encode('utf-8'))
        self.textBrowser.append("Spidey!")
        time.sleep(1)

        self.textBrowser.append("Resetting to neutral...")
        ser.write('n'.encode('utf-8'))
        self.textBrowser.append("Reset!")

        ser.close()
        self.progressBar.setValue(100)


def main():
    app  =  QApplication ([]) 
    window  =  MatplotlibWidget()
    window . show () 
    window.resize(607, 682)
    window.update()
    app . exec_ ()

if __name__ == '__main__':
    main()