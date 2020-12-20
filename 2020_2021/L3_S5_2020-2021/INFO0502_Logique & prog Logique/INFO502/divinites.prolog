divinite_primordiale(chaos).
divinite_primordiale(nyx).
divinite_primordiale(erebe).
divinite_primordiale(tartare).
divinite_primordiale(eros).
divinite_primordiale(gaia).
divinite_primordiale(ouranos).

titan(cronos).
titan(rhea).
titan(aphrodite).

divinite(zeus).
divinite(aphrodite).
divinite(hestia).
divinite(hera).
divinite(poseidon).
divinite(ares).
divinite(hephaistos).
divinite(apollon).
divinite(artemis).
divinite(dionysos).
divinite(athena).
divinite(hermes).
divinite(hades).
divinite(demeter).
divinite(persephone).
divinite(ilithye).
divinite(hebe).

demi_divinite(heracles).

humaine(alcmene).

femelle(nyx).
femelle(gaia).
femelle(eris).
femelle(rhea).
femelle(aphrodite).
femelle(hestia).
femelle(demeter).
femelle(hera).
femelle(persephone).
femelle(ilithye).
femelle(hebe).
femelle(alcmene).
femelle(leto).
femelle(semele).
femelle(metis).
femelle(maia).
femelle(artemis).
femelle(athena).

male(chaos).
male(erebe).
male(tartare).
male(eros).
male(ouranos).
male(hekatonchires).
male(cyclopes).
male(cronos).
male(zeus).
male(poseidon).
male(hades).
male(ares).
male(hephaistos).
male(heracles).
male(apollon).
male(dionysos).
male(hermes).

%enfant où on connait les 2 parents
fruit_de(hestia, cronos, rhea).
fruit_de(hestia, rhea, cronos).
fruit_de(demeter, cronos, rhea).
fruit_de(demeter, rhea, cronos).
fruit_de(hera, cronos, rhea).
fruit_de(hera, rhea, cronos).
fruit_de(zeus, cronos, rhea).
fruit_de(zeus, rhea, cronos).
fruit_de(poseidon, cronos, rhea).
fruit_de(poseidon, rhea, cronos).
fruit_de(hades, cronos, rhea).
fruit_de(hades, rhea, cronos).
fruit_de(ares, hera, zeus).
fruit_de(ares, zeus, hera).
fruit_de(ilithye, hera, zeus).
fruit_de(ilithye, zeus, hera).
fruit_de(hebe, hera, zeus).
fruit_de(hebe, zeus, hera).
fruit_de(hephaistos, hera, zeus).
fruit_de(hephaistos, zeus, hera).
fruit_de(persephone, demeter, zeus).
fruit_de(persephone, zeus, demeter).
fruit_de(heracles, alcmene, zeus).
fruit_de(heracles, zeus, alcmene).
fruit_de(apollon, leto, zeus).
fruit_de(apollon, zeus, leto).
fruit_de(artemis, leto, zeus).
fruit_de(artemis, zeus, leto).
fruit_de(dionysos, semele, zeus).
fruit_de(dionysos, zeus, semele).
fruit_de(athena, metis, zeus).
fruit_de(athena, zeus, metis).
fruit_de(hermes, maia, zeus).
fruit_de(hermes, zeus, demeter).

%enfant sans la connaissance des 2 parents
fruit_de(nyx,chaos).
fruit_de(erebe,chaos).
fruit_de(tartare,chaos).
fruit_de(eros,chaos).
fruit_de(gaia,chaos).
fruit_de(eris, nyx).
fruit_de(ouranos, gaia).
fruit_de(hekatonchires, ouranos).
fruit_de(cyclopes, ouranos).
fruit_de(cronos, ouranos).
fruit_de(rhea, ouranos).
fruit_de(aphrodite, ouranos).
fruit_de(apollon, leto).
fruit_de(artemis, leto).
fruit_de(dionysos, semele).
fruit_de(athena, metis).
fruit_de(hermes, maia).