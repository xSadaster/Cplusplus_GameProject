# Project Progress & Requirements (Papun muistiinpanot)

## Mitä ollaan tehty

1. **Luokkahierarkia**
- On abstrakti base class (GameComponent), siitä periytyvä Character, ja siitä taas Player, Enemy jne. (ja niistä vielä Warrior, Tank, Berserker)
- Kaikissa on oletus- ja parametrikonstruktori, destruktori löytyy myös.
- Suojatut/privaattimuuttujat, getterit/setterit käytössä.

2. **Polymorfismi**
- show() ja act() on virtuaalisia, overridettu aliluokissa.
- Käytetään taistelussa (Player/Enemy act() jne.)

3. **Operaattorin ylikuormitus**
- << ylikuormitettu Enemy-luokalle (eli vihun statseja voi tulostaa suoraan coutilla)

4. **Konstruktorit & destruktorit**
- Kaikissa tärkeissä luokissa on useampi konstruktori ja destruktori.

5. **Dynaaminen olionluonti**
- Pelaaja luodaan new:lla (Player* Playable_character = new ...)

6. **Tietorakenteet**
- Käytössä taulukko (array) karttaan.

7. **using namespace**
- Kaikissa tiedostoissa on using namespace std;

8. **Bossi & Hyvä Ending**
- Kartan vasempaan alakulmaan lisätty bossi (77), jonka voittamalla peli päättyy "hyvään endingiin".

---

## Mitä puuttuu/vielä tekemättä

- Operaattorin ylikuormitus: vain << tehty, toinen (esim. +) puuttuu vielä.
- Tietorakenteet: ei ole vielä set/map käytössä (esim. inventaariossa voisi olla map).
- Dynaamisen sidonnan esimerkki: ei ole vielä mainissa kohtaa, jossa base class -pointterilla kutsutaan virtuaalifunktiota (esim. GameComponent* ptr = new Warrior(...); ptr->show();)

---

## Suositukset (että menee varmasti läpi)
- Tee vielä toinen operaattorin ylikuormitus (esim. + Inventorylle tai Playerille)
- Käytä std::map tai std::set jossain (esim. inventaario, löydetyt paikat tms)
- Lisää mainiin kohtaa, jossa base class -pointterilla kutsutaan virtuaalifunktiota (dynaaminen sidonta)

---

Nämä muistiinpanot on tehty arviointia ja omaa seurantaa varten. Katso koodikommenteista tarkemmat paikat missä mikäkin vaatimus täyttyy!
