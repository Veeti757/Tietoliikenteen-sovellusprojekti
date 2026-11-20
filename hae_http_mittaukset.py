
import requests

url = "http://172.20.241.9/luedataa_kannasta_groupid_csv.php?groupid=29"

try:
    vastaus = requests.get(url, timeout=15)
    vastaus.raise_for_status()

    with open("mittaukset.csv", "wb") as tiedosto:
        tiedosto.write(vastaus.content)

    print("Mittausdata haettu onnistuneesti!")
    print("Tallennettu tiedostoon mittaukset.csv")

except requests.RequestException as virhe:
    print("Tietojen hakeminen epäonnistui:", virhe)
