BlockEdit:
BlockEdit je editor a interpret hierarchicky štrukturovaných funkčných blokov.
Ako úložisko sa využíva súbor JSON, ktorý je umiestnený v súbore: src/Storage/categories.json.

Implementovaná funkcionalita:
- Kategórie
    - Knihovňa kategórií (v ľavom paneli)
    - Vytváranie kategórií
    - Úprava kategórií
    - Mazanie kategórií
- Atomické bloky
    - Knihovňa atomických blokov (v ľavom paneli)
    - Vytváranie atomických blokov (do kategórie alebo iba na scénu)
    - Úprava atomických blokov (v kategórií a na scéne)
    - Mazanie atomických blokov (v kategórií a na scéne)
- Generovanie kódu
    - Generovanie kódu z pospájaných blokov
    - Pripájanie rôzne typy inputov
    - Pripájanie outputov (výpis na výstup)

Obmedzenia funkcionalít: -

GUI
- GUI obsahuje dva hlavné prvky:
    - Bočný panel
    - Hlavná scéna
- Bočný panel obsahuje:
    - prepínanie módov aplikácie
    - pri móde "create" sa zobrazia možnosti pridávania blokov, prepojení, vstupov a výstupov
    - kategórie
    - generovanie programu zo scény

Módy aplikácie
- Select (ukazateľ myši)
    - V tomto móde sa dajú objekty na scéne pohybovať prípadne pridávať z bočného panela kategórií na scénu.
- Create (plus symbol)
    - V tomto móde sa vytvárajú nové objekty (bloky, prepojenia, vstupy a výstupy)
    - Pri vybraní tohto módu sa aktivuje pod-sekcia kde sa dajú jednotlivé objekty prepínať
    - Po kliknutí na scénu sa na danom mieste vygeneruje daný objekt
- Edit (symbol úpravy)
    - V tomto móde sa upravujú bloky ako v kategórií tak aj v scéne
    - V prípade kliknutia na blok v bočnom paneli otvorí sa dialóg, v ktorom je možné daný blok upraviť
      (tieto zmeny sa uložia aj do úložiska)
    - V prípade kliknutia na blok v scéne sa otvorí dialóg, v ktorom je možné daný blok upraviť
      (tieto zmeny sa aplikujú len na konkrétny blok na scéne)
- Delete (symbol koša)
    - V tomto móde sa mažú jednotlivé objekty na scéne prípadne bloky z kategórií (v bočnom paneli)ň
    - V prípade kliknutia na blok v kategórií (okrem základných) sa daný blok vymaže z kategórie (úložiska)
    - V prípade kliknutia na objekt v scéne sa daný objekt vymaže iba zo scény

Vytváranie kategórií
- Kategória sa vytvorí kliknutím na symbol plus vpravo od "Categories".
- Po kliknutí sa zobrazí dialóg, v ktorom sa zadá názov kategórie

Vytváranie blokov
- Bloky sa dajú vytvárať do kategórie alebo iba na scénu
- V móde Create po kliknutí na scénu sa otvorí dialóg, v ktorom je možné vytvoriť blok,
  (pokiaľ sa nevyberie kategória pridá sa iba na scénu)
- Vstupy:
    - Vstupy sa zapisujú následovným formátom: "TYP:NÁZOV"
    - Jednotlivé vstupy sa oddelujú novým riadkom
    - Možné typy: INT,FLOAT,STRING,BOOL
- Výstupy:
    - Výstupy sa zapisujú rovnakým spôsobom
- Kód:
    - Kód sa zapisuje iba ako telo funkcie
    - Každá funkcia je typu void, preto je nutné zapisovať výstup do premennej výstupu
    - Príklad kódu konkatenácie dvoch reťazcov (vstupy:string:A,string:B|výstupy:string:C):
    C = A + B;

Generovanie kódu
- Kód sa generuje kliknutím na ikonku vedľa "Build program"
- Otvorí sa nový dialóg, v ktorom sa zadá názov súboru a vyberie sa cesta, kde sa súbor uloží
- Po kliknutí na "Build a program" sa daný súbor vygeneruje na vybrané miesto