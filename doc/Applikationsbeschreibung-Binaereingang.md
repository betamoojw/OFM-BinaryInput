# **Binäreingänge**

<!-- DOC HelpContext="Dokumentation" -->
Das Modul für Binäreingänge erlaubt eine einfache Definition von Schaltzuständen über einen Binäreingang. Derzeit werden von der zugehörigen Applikation Schalter oder Fensterkontakte unterstützt, keine Impulseingänge, deren Werte gezählt werden sollen.
<!-- DOCEND -->

## **Allgemein**

Auf dieser Seite sieht man die in der Applikation verwendete Modulversion und die Anzahl der Binäreingänge, die der Benutzer verwenden möchte.

### **Verfügbare Kanäle**

Um die Applikation übersichtlicher zu gestalten, kann hier ausgewählt werden, wie viele Kanäle in der Applikation verfügbar und editierbar sind. Die Maximalanzahl der Kanäle hängt von der Firmware des Gerätes ab, dass dieses Modul verwendet.

Die ETS ist auch schneller in der Anzeige, wenn sie weniger (leere) Kanäle darstellen muss. Insofern macht es Sinn, nur so viele Kanäle anzuzeigen, wie man wirklich braucht.

## **Eingang *x***

Da alle Eingänge gleich aussehen, wird hier nur ein Eingang Beschrieben. In der Applikation wird das *x* durch einen Buchstaben ersetzt, der die Nummer des Binäreingangs repräsentiert.

Folgende Eingaben stehen für die Konfiguration zur Verfügung:

<kbd>![Konfiguration](Screenshot%201.png)</kbd>

In den folgenden Unterkapiteln werden diese Eingaben beschrieben.

<!-- DOC -->
### **Beschreibung**

Der hier angegebene Name wird an verschiedenen Stellen verwendet, um diesen Kanal wiederzufinden.

* Seitenbeschreibung des Kanals
* Name vom Kommunikationsobjekt

Eine aussagekräftige Benennung erlaubt eine einfachere Orientierung innerhalb der Applikation, vor allem wenn man viele Kanäle nutzt.


<!-- DOC -->
### **Aktiv**

Damit der Binäreingang verwendet werden kann, muss er aktiv geschaltet werden.

<!-- DOC -->
### **Entprellung**

Eine Entprellung ist ein Verfahren, das dazu dient, unerwünschte Signale, die bei der Betätigung eines Schalters oder einer Taste entstehen können, zu entfernen. Wenn man beispielsweise eine Taste drückt, kann es vorkommen, dass das Signal mehrfach erfasst wird, was zu ungewollten Effekten führen kann. Die Entprellung sorgt dafür, dass nur das tatsächliche Signal erkannt wird und andere Signale herausgefiltert werden.

<!-- DOC -->
### **Geöffnet**

Hier wird festgelegt, welcher Status bei einem geöffneten Stromkreis gesendet werden soll.

#### **Deaktiviert**

Wenn der Status Deaktiviert gewählt wurde, wird beim geöffneten Stromkreis kein Signal gesendet.

#### **Aus**

Beim geöffneten Stromkreis wird ein Aus-Signal gesendet.

#### **Ein**

Beim geöffneten Stromkreis wird ein Ein-Signal gesendet.


<!-- DOC -->
### **Geschlossen**

Hier wird festgelegt, welcher Status bei einem geschlossenen Stromkreis gesendet werden soll.

#### **Deaktiviert**

Wenn der Status Deaktiviert gewählt wurde, wird beim geschlossenen Stromkreis kein Signal gesendet.

#### **Aus**

Beim geschlossenen Stromkreis wird ein Aus-Signal gesendet.

#### **Ein**

Beim geschlossenen Stromkreis wird ein Ein-Signal gesendet.

<!-- DOC -->
### **Zyklisch senden**

Hier kann die Zeit angegeben werden, nach der das letzte gesendete Signal erneut gesendet werden soll. Dieser Vorgang wird ohne Unterbrechung wiederholt.

Wird als Zeit 0 angegeben, wird nicht wiederholt. In einem solchen Falle sollte man "Zyklisch senden" auf Nein stellen.

#### **Zeitangabe für zyklisch senden**

Im Zahlenfeld wird das Zeitintervall eingegeben, über das dahinterliegende Auswahlfeld die Zeiteinheit. Es können Intervalle von bis zu 16.000 Sekunden, Minuten oder Stunden angegeben werden.


