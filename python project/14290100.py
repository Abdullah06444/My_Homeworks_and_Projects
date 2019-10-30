import random
import time
import sys
from tkinter import *

win=Tk()

win["bg"]="yellow"
win.title("MEMORY GAME")

wingenislik = 700
winyukseklik = 500

ekrangenislik = win.winfo_screenwidth()
ekranyukseksik = win.winfo_screenheight()
x = (ekrangenislik - wingenislik) / 2
y = (ekranyukseksik - winyukseklik) / 2
win.geometry("%dx%d+%d+%d"%(wingenislik,winyukseklik, x, y))

level=3
liste = []

def numbers():
	
	global level
	global liste
	global basla
	global baslamatext
	baslamatext.destroy()
	basla.destroy()

	win["bg"]="orange"

	# geri sayim
	for i in range(4):
		counter=Label(font="courier 300",fg="brown1",bg="orange")
		counter.place(relx=0.5,rely=0.5, anchor=CENTER)
		counter["text"]= 3-i
		win.after(500) # digitler arasindaki gecis
		win.update()
		counter["text"]=" "
		win.after(500) # digitlerin ekranda gorunme suresi
		win.update()
		counter.place(relx=0.5,rely=0.5, anchor=CENTER)

	# ekranda rastgele yerlere sayilari atar.
	etiket=Label(font="courier 50",fg="black",bg="orange")
	bb=random.uniform(0,0.8)
	cc=random.uniform(0,0.8)
	etiket.place(relx=bb, rely=cc)
	
	displaylevel()

	for i in range(level):
		while len(liste) != level:
			a = random.randint(0,9)
			if i>0 and a==liste[i-1]:
				continue
			else: # bunu yazmazsam sonsuz dongu olusur
				liste.append(a)
		etiket["text"]=liste[i]
		win.after(500) # digitler arasindaki gecis
		win.update()
		etiket["text"]=" "
		if level<10:
			win.after(500) # digitlerin ekranda gorunme suresi
			win.update()
		else:
			win.after(500*(level/5))  # digitlerin ekranda gorunme suresi
			win.update()
		bb=random.uniform(0,0.8)
		cc=random.uniform(0,0.8)
		etiket.place(relx=bb, rely=cc)
	level +=1
	
	enter()

def enter():
	# ciktiyi yazdigim kisim
	girdi = Entry(width=34,bg="brown1",font="courier 32",fg="blue")
	girdi.place(relx=0.0,rely=0.40)
	xxx = lambda: control(girdi,cont)

	cont=Button(text="DONE",command=xxx,font="courier 34",fg="white",bg="lightskyblue")
	cont.place(relx=0.4, rely=0.6)

	# baslangictaki level (with 3 numbers) kismi
def displaylevel():
	whichlevel=Label(font="courier 35",fg="turquoise",bg="orange")
	whichlevel.place(relx=0.5, rely=0.2, anchor=CENTER)
	whichlevel["text"]="LEVEL "+str(level-2)+"\n("+str(level)+" numbers)"
	# start goruntusunden sonrakine gecis suresini yazmaya gerek yok
	win.update()

	whichlevel["text"]="" # bu sayede yazilan kismi diger hamlede yok edebilirim.
	win.after(1000) # diger bir goruntuye gecme suresi 500
	win.update()

def control(girdi,cont):

	global liste
	global level
	metin=girdi.get()#yazdigim degeri okumuya yarar.
	xxx = lambda: isok(girdi,cont,metin)
	xxx()

def isok(girdi,cont,metin):
	global liste
	girdi.destroy()#bunlar done komutundan sonra
	cont.destroy() #eskisini gostermemesi icin
	chec=1
	a=1
	if len(metin) != len(liste):
		score=Label(text="Your score is ",font="courier 50",fg="white",bg="orange")
		score.place(relx=0.5, rely=0.2, anchor=CENTER)
		score["text"] += str(level-4)
		wrong=Label(text="DIGITS ARE\nDIFFERENT",font="courier 30",fg="white",bg="green")
		wrong.place(relx=0.5, rely=0.5, anchor=CENTER)
		exitt=Button(text="GAME OVER",command=exit, height=2,font="courier 24",fg="white",bg="blue")
		exitt.place(relx=0.35,rely=0.75)
		a=0

	if a==1:
		for i in range(level-1):
			if ord(metin[i])-48 != liste[i]:
				chec=0
	
		xxx = lambda: check(girdi,cont,metin,chec)
		xxx()

def check(girdi,cont,metin,a):
		global liste
		# kontrol edildigi kisim
		win["bg"]="orange"
		number=Label(text="NUMBER",font="courier 30",fg="green",bg="orange")
		number.place(relx=0.38, rely=0.18)
		number["text"]+="\n"
		for i in range(level-1):
			number["text"]+=str(liste[i])

		answer=Label(text="YOUR ANSWER",font="courier 25",fg="brown",bg="orange")
		answer.place(relx=0.33, rely=0.35)
		answer["text"]+="\n"+metin
		
		if a==1:
			xxx = lambda: nextlevel(girdi,cont,metin,number,answer,next)
			win.after(500)
			win.update()
			# seviyelere rutbe atadim
			if level<7:
				next=Button(text="NEXT LEVEL\nGOOD",command=xxx,height=4,font="courier 24",fg="white",bg="lightskyblue")
				next.place(relx=0.5, rely=0.75, anchor=CENTER)
			else:
				if level<10:
					next=Button(text="NEXT LEVEL\nPERFECT", command=xxx, height=4,font="courier 24", fg="white", bg="lightskyblue")
					next.place(relx=0.5, rely=0.75, anchor=CENTER)
				else:
					if level<13:
						next=Button(text="NEXT LEVEL\nEXCELLENT", command=xxx, height=4,font="courier 24", fg="white", bg="lightskyblue")
						next.place(relx=0.5, rely=0.75, anchor=CENTER)
					else:
						next=Button(text="NEXT LEVEL\nGENIUS", command=xxx, height=4, font="courier 24", fg="white", bg="lightskyblue")
						next.place(relx=0.5, rely=0.75, anchor=CENTER)

		else:
			score = Label(text="Your score is ", font="courier 50", fg="white", bg="orange")
			score.place(relx=0.5, rely=0.1, anchor=CENTER)
			score["text"] += str(level - 4)
			next2=Button(text="GAME OVER",command=exit,height=2,font="courier 24",fg="white",bg="lightskyblue")
			next2.place(relx=0.5, rely=0.75, anchor=CENTER)

def nextlevel(girdi,cont,metin,number,answer,next):
	global liste	
	liste=[]
	girdi.destroy()
	cont.destroy()
	metin=""
	number.destroy()
	answer.destroy()
	next.destroy()
	numbers()

def exit():
	win.destroy()

baslamatext=Label(text="MEMORY GAME",font="courier 34",fg="white",bg="green")
baslamatext.place(relx=0.5, rely=0.5, anchor=CENTER)

basla=Button(text="START",command=numbers,width=4, height=2,font="courier 24",fg="white",bg="blue")
basla.place(relx=0.35,rely=0.60,relheight=0.125,relwidth=0.25)

win.mainloop()

