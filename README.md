# C-OOP-project
Aplicatie de tip consola in C++, care permite gestiunea profilelor senzorilor dintr-un sistem IoT(Internet of Things)

## Tehnologii folosite:
- C++ language
- OOP (Object Oriented Programming)

## Clasele Folosite :
- class Operatori – reprezinta clasa TEMPLATE
- class Dispozitiv- reprezinta o clasa abstracta  , repectiv clasa parinte a clasei ‘Senzor’
- class Profil-reprezinta clase de profile pt senzori , alcatuita din 4 atribute cheie
- class Senzor-reprezinta o clasa ce contine toate atributele masurate pt. stabilirea profilului
- class CasaInteligenta- reprezinta sistemul nostru IoT , si contine un vector de senzori , respectiv un atribut ‘Rating’ , calculat pe baza profilelor senzorilor din Casa Inteligenta respectiva , dupa cum se explica mai jos 

### Algoritmul de stabilire a profilului senzorilor si de determinare a gradului de inteligenta pentru sistemul IoT ; profilul unui sensor consta in stabilirea celor 4 atribute din clasa Profil:
- string clasa;
- int garantie;
- bool waterproof;
- string tipRetea;
