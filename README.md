# Tietoliikenteen-sovellusprojekti

## Projektin kuvaus

Projektin tavoitteena on lukea kiihtyvyysanturin mittausarvoja nRF5340 DK -kehitysalustalla ja myöhemmin hyödyntää mittausdataa Raspberry Pi -laitteella.

## Käytettävät laitteet

- **nRF5340 DK** – kehitysalusta
- **GY-61 (ADXL335)** – kolmiakselinen kiihtyvyysanturi
- **Raspberry Pi** – mittausdatan vastaanottamiseen ja käsittelyyn
- **Koekytkentälevy** – komponenttien kytkemiseen

## Ohjelmistot ja työkalut

- Visual Studio Code
- nRF Connect SDK
- Zephyr RTOS
- C-ohjelmointikieli
- Git ja GitHub

## Kiihtyvyysanturin lukeminen

GY-61-kiihtyvyysanturi mittaa kiihtyvyyttä kolmella akselilla:

- X-akseli
- Y-akseli
- Z-akseli

Anturi tuottaa analogisia jännitesignaaleja, jotka luetaan nRF5340 DK:n ADC-muuntimella.

## Tekijät

Veeti Kokkonen