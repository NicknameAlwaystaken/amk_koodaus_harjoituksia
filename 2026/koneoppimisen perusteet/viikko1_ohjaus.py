import enum
from math import tau
import random


def tervehdysjaroolit():
    rooli = input("Anna rooli: ")

    if rooli.lower() == "asiakas":
        print("Tervetuloa kahvilaan!")
    elif rooli.lower() == "tyontekija":
        print("Tervetuloa toihin!")
    else:
        print("Tuntematon rooli.")

def lampotilanarviointi():
    lampotila = int(input("Anna lampotila: "))

    if lampotila < 10:
        print("Mainosta kuumia juomia.")
    elif lampotila > 20:
        print("Mainosta kylmia juomia.")
    else:
        print("Mainosta sekä kuumia että kylmiä juomia.")


def tuotelistaus():
    kahvilalista = [
        "kahvi",
        "leipa",
        "jani",
        "ilari",
        "makkara",
        "kroisantti",
    ]

    for item in kahvilalista:
        print(item)


def ostoskorinrakentaminen():
    ostoskori = {}
    total_price = 0
    while(True):
        new_product = input("Anna tuote: ")
        if not new_product:
            break;

        new_price = int(input("\nAnna hinta tuotteelle: "))

        ostoskori[new_product] = new_price

        total_price += new_price

    for key, value in ostoskori.items():
        print(key, " maksaa ", value, "e")

    print("Yhteishinta ", total_price, "e")


def erikoistarjous():

    ostoskori = []

    erikoistarjous = ("kirja", 10)

    print("Ostatko erikoistarjouksesta ", erikoistarjous[0], " maksaa ", erikoistarjous[1])
    ostaako = input("\nK/E\n")

    if ostaako.lower() == "k":
        ostoskori.append(erikoistarjous)
        print("Lisatty koriin!")
    else:
        print("Ei lisatty koriin")

def asiakasarvostelut():
    asiakasarvostelut = []
    a_count = 0

    for i in range(3):
        arvostelu = input("Anna arvostelu: ")
        asiakasarvostelut.append(arvostelu.upper())
        for c in arvostelu:
            if c.lower() == "a":
                a_count += 1


    print(asiakasarvostelut)
    print(f"\na kirjain esintyy: {a_count} kertaa")


def myynnintilastointi():
    suurinmyynti = 0
    myyntipaiva = 0
    kokonaismyynti = 0

    for i in range(7):
        myynti = int(input("Anna myyntimaara: "))
        kokonaismyynti += myynti
        if suurinmyynti < myynti:
            suurinmyynti = myynti
            myyntipaiva = i

    paivalista = ["ma", "ti", "ke", "to", "pe", "la", "su"]

    print(f"Paras paiva {paivalista[myyntipaiva]}, kokonaismyynti {kokonaismyynti}, keskimaarainen {kokonaismyynti / 7.0}")


def arvaaerikoistuote():
    tuotelista = ["kirja", "pyora", "lappari", "kahvikuppi", "ilmapallo"]
    tuote = random.choice(tuotelista)

    tuote_index = tuotelista.index(tuote)
    arvaus_index = 0

    while(1):
        arvaus = input("\nAnna tuote: ")
        if arvaus.lower() == tuote:
            print("\nOikein!")
            break
        else:
            for key, value in enumerate(tuotelista):
                if(value == arvaus.lower()):
                    arvaus_index = key
                    break

            if arvaus_index < tuote_index:
                print("Tuote on oikeammalla")
            else:
                print("Tuote on vasemmalla")

            print(tuotelista)


def kertotaulu():
    taulukko = []

    for i in range(1, 6):
        rivi = []
        for j in range(10, 15):
            rivi.append(i * j)

        taulukko.append(rivi)

    for row in taulukko:
        print(f"{row}")


def lampotilaanalyysi():
    lampotilat = [10, 12, 1, -5, 25, 22, 5]

    print(f"Kesimaarainen {sum(lampotilat) / len(lampotilat)}, kylmin {min(lampotilat)}, kuumin {max(lampotilat)}")


if __name__ == "__main__":
    # tervehdysjaroolit()
    # lampotilanarviointi()
    # tuotelistaus()
    # ostoskorinrakentaminen()
    # erikoistarjous()
    # asiakasarvostelut()
    # myynnintilastointi()
    # arvaaerikoistuote()
    # kertotaulu()
    lampotilaanalyysi()

