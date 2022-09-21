# Conveyor-belt-with-sorting-system-
## Opis projekta
Projekat se sastoji iz pokretne trake koja prenosi teret i mehaničke ruke koja razvrstava teret na osnovu njegove boje. Projekat predstavlja pojednostavljen model industrijske trake za sortiranje tereta.

## Hardver
Traka se sastoji iz dve valjkaste osovine od kojih se jedna pokreće dc motorom, a preko kojih se nalazi traka od gume. Sa jedne strane trake nalazi se mehanička ruka koja se aktivira kada se iznad infracrvenog senzora nadje prepreka tj. teret. Mehanička ruka sastoji se iz hvataljke na vrhu koja se pokreće jednim servo motorom, na dnu se nalazi step motor koji okreće celu ruku. Ruka dovozi teret iznad senzora boje pre nego što sortira teret na osnovu očitane boje.
Infracrveni senzor pokreta povezan je sa arduinom, njegovom aktivacijom pokreće se sekvenca kojim se zaustavlja dc motor koji pokreće traku i pomera se mehanička ruka.  Napajanje dc motora koji pokreće traku kontroliše se arduinom. Servo motor koji pokreće hvataljku napaja se i kontroliše putem arduina. Step motor ima eksterno napajanje i kontrolisan je drajverom koji je povezan i napaja se putem arduina. Step motor okreće ruku, u kojoj se nalazi teret, do senzora za boju. Senzor za boju povezan je i napaja se arduinom. Ruka se dalje okreće i ostavlja teret na mesto koje odgovara očitanoj boji, posle čega završava rotaciju i vraća se u početnu poziciju, dc motor nastavlja da radi do sledeće aktivacije senzora pokreta.

## Softver
Infracrveni senzor vraća LOW vrednost kad je detektovan objekat ispred njega, u suprotnom vrednost ostaje HIGH. Ukoliko je digitalno čitanje pina za infracrveni senzor nula prekida se napon na dc motoru koji pokreće traku, a servo pomera hvataljku za odredjen broj stepeni, koji smo odredili višestrukim testiranjem. Zatim steper motor okreće telo hvataljke za odredjen broj koraka, tako da se teret nadje ispred senzora boje. Bilo je potrebno izvršiti kalibraciju senzora. Selektovanjem odredjenih dioda u mogućnosti smo da dobijemo intenzitet različitih boja. Sledeći korak jeste uslovno sortiranje prema boji objekta i rotacija stepper motora do odredjenog mesta. Servo motor vraća hvataljku na početnu poziciju, pri čemu dolazi do ispuštanja objekta, i na kraju dolazi do rotacije hvataljke tela do početne pozicije.

## Zaključak
Bilo je potrebno napraviti šemu za povezivanje elektronike, softver koji bi je pokretao i mašinski deo koji bi podržavao elektroniku. Poteškoće su se javljale u izboru, implementaciji i optimizovanju elektronskih komponenti kao sto su senzori boje i pokreta. Bilo je izazovno implementovati steper motor sa odgovarajućim drajverom i kodom.
Planiramo da povećamo funkcionalnost sistema dodatnim senzorima za provodnost, težinu, veličinu isl. Poboljšanja u vidu veće nosivosti trake i robotske ruke su takodje u planu.

## Komponente
1. Arduino UNO
2. NEMA 17 Stepper motor
3. Sg90 Servo motor
4. DRV8825 Stepper motor driver 
5. DC motor sa gearbox-om
6. IR senzor prepreke
7. TCS3200 senzor boje
8. IRF640 MOSFET tranzistor
9. kondenzator od 100 mikrofarada


