# ProiectPOO
Proiect POO An I Sem II

Nume proiect: Clinica_medicala

Tema: gestiunea unei clinici medicale

Clase folosite: clasa String, clasa Pacient, clasa Medic, clasa Asistent_medical, 
clasa Cabinet, clasa Consultatie si clasa Departament.

Clasa String:
-este o clasa utilitara, pentru siruri de caractere
-aloca dinamic siruri de caractere
Clasa Pacient:
-este o clasa ce are drept scop retinerea informatiilor despre pacientii ce sunt inregistrati la clinica
-campurile clasei sunt constituite de nume, prenume, sex, numar de telefon, varsta, codul pacientului, starea asigurarii medicale(asigurat sau neasigurat), starea abonamentului(abonat sau neabonat), greutatea si inaltimea
-in ceea ce priveste constructorii, clasa are atat constructor fara parametru(initializeaza pacientul cu date standard) cat si constructor cu parametru(seteaza valorile pentru toate campurile obiectului)
-clasa are getteri si setteri construiti pentru toate campurile
-clasa are definit operatorul de atribuire "=" ce ne da astfel posibilitatea sa copiam toate datele de la un pacient la alt pacient
-clasa are posibilitatea si de a se afisa toate elementele pe ecran, prin supraincarcarea operatorului "<<"
Clasa Medic:
-este o clasa ce are drept scop retinerea informatiilor despre medicii ce lucreaza la clinica
-campurile clasei sunt constituite de nume, prenume, cod(identificator unic pentru fiecare medic), sex, numar de telefon, varsta, specialitate, grad si salariu
-are atat constructor fara parametru ce initializeaza datele cu date standard, cat si un constructor cu parametri ce da valorile date fiecarui camp al obiectului declarat
-sunt definiti getteri si setteri pentru toate campurile
-este realizata supraincarcarea operatorului << pentru afisarea tuturor datelor clasei
-este definit operatorul == pentru a verifica egalitatea a doua obiecte de tip medic(aceasta egalitate va fi stabilita doar in functie de nume, prenume, sex si cod)
-este definit si operatorul de atribuire = pentru a putea copia toate valorile dintr-un obiect de tip medic in alt obiect de tip medic
Clasa Asistent_medical:
-este o clasa ce are drept scop retinerea informatiilor cu privire la asistentii medicali ce sunt angajati in clinica 
-campurile clasei sunt numele, prenumele, sexul, numarul de telefon, varsta, salariul si gradul
-sunt definiti constructori atat cu parametru, cat si fara parametru
-sunt definiti getteri si setteri pentru toate datele
-este definit operatorul de atribuire =
-este supraincarcat operatorul << pentru a putea afisa datele din obiect
Clasa Cabinet:
-este o clasa ce are drept scop retinerea informatiilor legate de cabinetele disponibile din clinica
-cele doua campuri ale clasei sunt specialitatea si denumirea efectiva a cabinetului
-sunt definiti constructori cu si fara parametri
-getteri si setteri
-este definit operatorul de atribuire =
-este definit un constructor de copiere
-este supraincarcat operatorul << pentru a putea afisa toate datele obiectului 
Clasa Consultatie:
-este o clasa ce reprezinta practic programarea unei persoane pe o anumita data la un anumit medic intr-un anumit cabinet
-campurile clasei sunt: data la care se face programarea, pretul consultatiei, pacientul, medicul, cabinetul si diagnosticul
-sunt definiti doi constructori, unul fara parametri si unul cu parametri
-sunt definite doua metode: prima metoda aplica o reducere de 100% pacientilor care sunt asigurati medical, cea de-a doua aplica o reducere de 30% acelor pacienti care sunt abonati la clinica
Clasa Departament:
-clasa departament constituie practic un inventar al tuturor medicilor care lucreaza intr-un anumit departament din cadrul clinicii
-campurile clasei sunt reprezentate de numarul de medici care lucreaza in departament si un vector de obiecte alocat dinamic care retine toti medicii ce lucreaza in departamentul respectiv
-clasa ure un constructor fara parametru care va crea un vector vid, iar numarul de angajati va fi egal cu 0
-totodata, clasa are un constructor cu parametri, in care i se va da un numar care va reprezenta numarul de medici si va aloca dinamic atata memorie de cata este nevoie in functie de numarul citit
-este declarat un getter ce poate lua numarul de medici
-sunt declarate 4 functii:
*prima functie, Adaugare_medic, adauga un medic nou in departament
*a doua functie, Eliminare_medic, elimina un medic din departament(daca acesta face parte din departament)
*a treia functie, Medie_salariu, calculeaza salariul mediu al medicilor din departamentul respectiv
*a patra functie, Marire_salariu, mareste salariul tuturor medicilor din departament cu 10%

Functionalitati:
La momentul actual, aplicatia este capabila sa retina un vector de medici ce lucreaza intr-un anumit departament, sa le calculeze salariul mediu, sa le dea o marire de salariu, sa adauge medici noi sau sa elimine medici vechi.
Aplicatia poate face consultatii, ce reprezinta programari se stabilesc intre medic, pacient si cabinet, fiind programate la o data si cu un anumit pret
Pacientii pot primi reduceri in functie de statutul lor: daca sunt abonati vor primi o reducere de 30%, iar daca sunt asigurati vor primi o reducere de 100%
Aplicatia poate sa inregistreze pacienti, medici, asistenti medicali, cabinete, departamente si consultatii.




