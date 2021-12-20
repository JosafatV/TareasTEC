import tkinter as tk
from tkinter import ttk
import threading
from threading import Thread, RLock
import os
import time
import json


print ("+++ Program started +++")

dark_grey = "#555555"




# btn event 1
def btn_button_event ():
    user_in = ent_entry.get()
    if (user_in == ""):
        ent_entry.insert(0, "Enter text here")
        #lbl_error(text = "No text in ent_entry")
    else:
        print (user_in)
        ent_entry.delete(0, tk.END) #clear tk.ent_entry


def cmb_callback_event(event):
    print (cmb_combo.get())



window = tk.Tk() # Create the window

frm_menu = tk.Frame(master = window,
                 background = "orange",
                 width = 100, height = 500)

frm_frame = tk.Frame(master = window,
                 background = dark_grey,
                 width = 500, height = 500)


lbl_label = tk.Label(master=frm_frame,
                    text="Hello, Tkinter",
                    fg = "white", bg = dark_grey,
                    width = 20, height = 5)

lbl_error = tk.Label(master=frm_frame,
                    text="error",
                    fg = "red", bg = dark_grey,
                    width = 5, height = 5)

btn_button = tk.Button(master=frm_frame,
                   text="Click here",
                   fg = "white", bg = dark_grey,
                   width = 10, height = 5,
                   command = btn_button_event)

ent_entry = tk.Entry(master=frm_frame,
                 fg = "yellow", bg = dark_grey,
                 width = 20)

cmb_combo = ttk.Combobox(master=frm_frame,
                         values = ["One", "Two", "Fart"],
                         state = "readonly",
                         width = 20)
cmb_combo.bind("<<ComboboxSelected>>", cmb_callback_event)

frm_menu.pack(fill=tk.BOTH, side=tk.LEFT, expand=True)
frm_frame.pack(fill=tk.BOTH, side=tk.LEFT, expand=True)

lbl_label.pack()
ent_entry.pack()
cmb_combo.pack()
lbl_error.pack()
btn_button.pack()

window.mainloop() #Tkinter event loop. This method listens for events






# ToDo: update label, multiple selection widget, read/update json config file, iterative GUI creation




