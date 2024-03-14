# C-OOP-project
Aplicatie de tip consola in C++, care permite gestiunea profilelor senzorilor dintr-un sistem IoT(Internet of Things)

# tehnologii folosite:
- C language
- OOP (Object Oriented Programming)
  

/*
Indicatorii masurati:
int numarInteractiuni=0;
int numarResetari=0;
int durataDeViata=0;
int* istoricDate=nullptr;
int dimensiuneIstoricDate=0;
char* pozitionare=nullptr;
float distantaFataDeUrmatorulSenzor=0;
float timpDeRaspuns=0;
bool conectareaDeLaDistanta=0;
string situatieCritica="";
bool interconectareCuAltiSenzori=0;
Toti acesti indicatori sunt attribute ale clasei ‘Senzor’

Clasele Folosite :
- class Operatori – reprezinta clasa TEMPLATE
-class Dispozitiv- reprezinta o clasa abstracta  , repectiv clasa parinte a clasei ‘Senzor’
-class Profil-reprezinta clase de profile pt senzori , alcatuita din 4 atribute cheie
-class Senzor-reprezinta o clasa ce contine toate atributele masurate pt. stabilirea profilului
-class CasaInteligenta- reprezinta sistemul nostru IoT , si contine un vector de senzori , respectiv un atribut ‘Rating’ , calculat pe baza profilelor senzorilor din Casa Inteligenta respectiva , dupa cum se explica mai jos 

Algoritmul de stabilire a profilului senzorilor si de determinare a gradului de inteligenta pentru sistemul IoT
-profilul unui sensor consta in stabilirea celor 4 atribute din clasa Profil:
string clasa;
int garantie;
bool waterproof;
string tipRetea;


1)profilul unui sensor este stabilit dupa cum urmeaza (in functie de atributele masurate ):



Atribute masurate pt stabilirea “tipRetea”
-float timpDeRaspuns
-bool conectareaDeLaDistanta;
		daca( conectare_de_la_distanta && timp_de_raspuns<1)
			tipRetea=satelit
		altfeldaca(conectare_de_la_distanta && timp_de_raspuns>1)
			tipRetea=antena;
		altfeldaca( !conectare_de_la_distanta && timp_de_raspuns<1)
			tipRetea=peertopeer;
		altfeldaca( !conectare_de_la_distanta && timp_de_raspuns>1)
			tipRetea=cablu;
Atribute masurate pt stabilirea “clasa”
-bool interconectareCuAltiSenzori;
		Daca este ‘true’ => clasa=monitorizare
		Daca este ‘false’=> clasa=supraveghere
Atribute masurate pt stabilirea “garantie”
 -int numarInteractiuni;
 -int numarResetari;
 -int durataDeViata;

FORMULA:
	garantie = (durata_de_viata + numar_resetari)/2 + (numar_intercatiuni/4)
Atribute masurate pt stabilirea “waterproof”
-char* pozitionare;

daca(pozitionare=baie || pozitionare=bucatarie)
				waterproof=true

altfel
				waterproof=false

2)gradul de inteligenta al sistemului IoT/Ratingul
-este calculat ca medie atritmetica intre gradul intermediar al fiecarui sensor

Gradul intermediar al senzorului/Ratingul intermediar
-Profilul senzorului(respectiv cele 4 atribute cheie ale profilului)vor intra intr-o cascada de ‘if-uri’ ,unde se va stabili un rating intermediar pt senzor , utilizat mai apoi pt a calcuat Rating-ul total/final al Casei Inteligente(Sistemul IoT)
STABILIREA Ratingului Intermediar :
satelit - monitorizare - garantie>20 - waterproof 1
		rating intermediar: 10
satelit - monitorizare - garantie>20 - waterproof 0
		rating intermediar: 9.8
satelit - monitorizare - garantie<20 - waterproof 1
		rating intermediar: 9.6
satelit - supraveghere - garantie>20 - waterproof 1
		rating intermediar: 9.4
satelit - monitorizare - garantie<20 - waterproof 0
		rating intermediar: 9.2
satelit - supraveghere - garantie>20 - waterproof 0
		rating intermediar: 9
satelit - supraveghere - garantie<20 - waterproof 1
		rating intermediar: 8.8
satelit - supraveghere - garantie<20 - waterproof 0
		rating intermediar: 8.6
antena - monitorizare - garantie>20 - waterproof 1
		rating intermediar: 8.4
antena - monitorizare - garantie>20 - waterproof 0
		rating intermediar: 8.2
antena - monitorizare - garantie<20 - waterproof 1
		rating intermediar: 8
antena - supraveghere - garantie>20 - waterproof 1
		rating intermediar: 7.8
antena-- monitorizare - garantie<20 - waterproof 0
		rating intermediar: 7.6
antena - supraveghere - garantie>20 - waterproof 0
		rating intermediar: 7.4
antena - supraveghere - garantie<20 - waterproof 1
		rating intermediar: 7.2
antena - supraveghere - garantie<20 - waterproof 0
		rating intermediar: 7
peertopeer - monitorizare - garantie>20 - waterproof 1
		rating intermediar: 6.8
peertopeer - monitorizare - garantie>20 - waterproof 0
		rating intermediar: 6.6
peertopeer - monitorizare - garantie<20 - waterproof 1
		rating intermediar: 6.4
peertopeer - supraveghere - garantie>20 - waterproof 1
		rating intermediar: 6.2
peertopeer - monitorizare - garantie<20 - waterproof 0
		rating intermediar: 6
peertopeer - supraveghere - garantie>20 - waterproof 0
		rating intermediar: 5.8
peertopeer - supraveghere - garantie<20 - waterproof 1

*/
