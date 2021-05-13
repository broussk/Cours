#ifndef OBJECTCOUNTERS_H
#define OBJECTCOUNTERS_H

#include <cstdio>
#define IN_RED(x)    printf("\033[0;31m"); x printf("\033[0m");
#define IN_GREEN(x)     "\033[0;32m" x "\033[0m"

struct Counters {
    // constructeur: iCD=par défaut, iCI=avec un entier, iCC=par copie, iCM=par déplacement
    // assignation: iAC=par copie, iAM=par déplacement
    // destructeur: iDD
    // voir la classe A (dans classA.h pour voir l'utilisation des compteurs)
    int iCD{}, iCI{}, iCC{}, iCM{}, iAC{}, iAM{}, iDD{};
    Counters() = default;
    Counters(int cd, int ci, int cc, int cm, int ac, int am, int dd):
        iCD(cd), iCI(ci), iCC(cc), iCM(cm), iAC(ac), iAM(am), iDD(dd) {}
    void reset() { iCD = iCI = iCC = iCM = iAC = iAM = iDD = 0; }
    friend bool operator==(const Counters& x, const Counters& y) {
        return (x.iCD == y.iCD) && (x.iCI == y.iCI) && (x.iCC == y.iCC) && (x.iCM == y.iCM) &&
               (x.iAC == y.iAC) && (x.iAM == y.iAM) && (x.iDD == y.iDD);
    }
    friend bool operator!=(const Counters& x, const Counters& y) { return !(x == y); }
    friend Counters operator-(const Counters& x, const Counters& y) {
        return Counters(x.iCD-y.iCD, x.iCI-y.iCI, x.iCC-y.iCC, x.iCM-y.iCM, x.iAC-y.iAC, x.iAM-y.iAM, x.iDD-y.iDD);
    }
};

// affiche tous les compteurs différents de zéro
void showNZ(const Counters& cnt) {
    if (cnt.iCD || cnt.iCI || cnt.iCC || cnt.iCM) {
        printf(" construct ( ");
        if (cnt.iCD) printf("def=%d ",cnt.iCD);
        if (cnt.iCI) printf("int=%d ",cnt.iCI);
        if (cnt.iCC) printf("copy=%d ",cnt.iCC);
        if (cnt.iCM) printf("move=%d ",cnt.iCM);
        printf(")");
    }
    if (cnt.iAC || cnt.iAM) {
        printf(" assign ( ");
        if (cnt.iAC) printf("copy=%d ",cnt.iAC);
        if (cnt.iAM) printf("move=%d ",cnt.iAM);
        printf(")");
    }
    if (cnt.iDD) printf(" destruct=%d",cnt.iDD );
}

// Cette classe est template uniquement afin qu'il y ait un jeu
// de compteur par la classe qui l'hérite, et non des compteurs globaux.
// Pour des compteurs globaux: prendre le même T (exemple: int)
template <class T> struct ObjectCounters {
static Counters count;
static Counters CounterGet() { return count; }
static Counters CounterReset() { count.reset(); return count; }

static Counters CounterInfo(const char *str=nullptr) {
    printf("Info %s: construct (def=%d, int=%d, copy=%d, move=%d) assign (copy=%d, move=%d) destruct=%d\n",
           (str ? str : ""), count.iCD, count.iCI, count.iCC, count.iCM, count.iAC, count.iAM, count.iDD);
    return count;
}

static Counters CounterDiff(const Counters& state, const char *str=nullptr, const Counters *ref=nullptr) {
    Counters diff = count - state;
    printf("%s:",(str ? str : ""));
    showNZ(diff);
    if (ref != nullptr) {
        Counters err = *ref - diff;
        if (err == Counters()) printf("%s",IN_GREEN(" succès"));
        else { IN_RED(printf("%s"," échec\n\t\t"); showNZ(err);) }
    }
    printf("\n");
    return count;
}
};

// déclaration externe du champs statique de la classe
template <class T> Counters ObjectCounters<T>::count;

#endif

