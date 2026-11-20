
import mysql.connector
import getpass
import csv

salasana = getpass.getpass("MySQL-salasana: ")

try:
    yhteys = mysql.connector.connect(
        host="172.20.241.9",
        user="dbaccess_ro",
        password=salasana,
        database="measurements",
        connection_timeout=10
    )

    kursori = yhteys.cursor()

    kursori.execute(
        "SELECT * FROM rawdata WHERE groupid = %s ORDER BY id DESC LIMIT 100",
        (29,)
    )

    rivit = kursori.fetchall()
    sarakkeet = [sarake[0] for sarake in kursori.description]

    with open("mysql_mittaukset.csv", "w", newline="", encoding="utf-8") as tiedosto:
        kirjoittaja = csv.writer(tiedosto)
        kirjoittaja.writerow(sarakkeet)
        kirjoittaja.writerows(rivit)

    print("Tietokantayhteys onnistui!")
    print("Haettuja mittauksia:", len(rivit))
    print("Tallennettu tiedostoon mysql_mittaukset.csv")

    kursori.close()
    yhteys.close()

except mysql.connector.Error as virhe:
    print("MySQL-virhe:", virhe)
