#include <stdio.h>
#include <string.h>

#define MAX_TAM_STRING (16)

// Tipo indefinido (quando não der match em alguma string.
#define INDEFINIDO (0b100000)
// Vertebrado ou invertebrado.
#define INVERTEBRADO (0b0)
#define VERTEBRADO   (0b1)
// Tipo de animal.
#define AVE      (0b000)
#define MAMIFERO (0b010)
#define INSETO   (0b100)
#define ANELIDEO (0b110)
// Tipo de alimentação.
#define CARNIVORO  (0b00000)
#define ONIVORO    (0b01000)
#define HERBIVORO  (0b10000)
#define HEMATOFAGO (0b11000)
// Animal.
#define AGUIA       (VERTEBRADO   + AVE      + CARNIVORO )
#define POMBA       (VERTEBRADO   + AVE      + ONIVORO   )
#define HOMEM       (VERTEBRADO   + MAMIFERO + ONIVORO   )
#define VACA        (VERTEBRADO   + MAMIFERO + HERBIVORO )
#define PULGA       (INVERTEBRADO + INSETO   + HEMATOFAGO)
#define LAGARTA     (INVERTEBRADO + INSETO   + HERBIVORO )
#define SANGUESSUGA (INVERTEBRADO + ANELIDEO + HEMATOFAGO)
#define MINHOCA     (INVERTEBRADO + ANELIDEO + ONIVORO   )

int getVertebradoFromString(const char *s) {
    if(s == NULL) {
        return INDEFINIDO;
    }
    if(strcmp(s, "vertebrado") == 0) {
        return VERTEBRADO;
    }
    if(strcmp(s, "invertebrado") == 0) {
        return INVERTEBRADO;
    }
    return INDEFINIDO;
}

int getTipoFromString(const char *s) {
    if(s == NULL) {
        return INDEFINIDO;
    }
    if(strcmp(s, "ave") == 0) {
        return AVE;
    }
    if(strcmp(s, "mamifero") == 0) {
        return MAMIFERO;
    }
    if(strcmp(s, "inseto") == 0) {
        return INSETO;
    }
    if(strcmp(s, "anelideo") == 0) {
        return ANELIDEO;
    }
    return INDEFINIDO;
}

int getAlimentacaoFromString(const char *s) {
    if(s == NULL) {
        return INDEFINIDO;
    }
    if(strcmp(s, "carnivoro") == 0) {
        return CARNIVORO;
    }
    if(strcmp(s, "onivoro") == 0) {
        return ONIVORO;
    }
    if(strcmp(s, "herbivoro") == 0) {
        return HERBIVORO;
    }
    if(strcmp(s, "hematofago") == 0) {
        return HEMATOFAGO;
    }
    return INDEFINIDO;
}

int getAnimalFromStrings(const char *vertebrado, const char *tipoAnimal, const char *alimentacao) {
    return getVertebradoFromString(vertebrado) +
        getTipoFromString(tipoAnimal) +
        getAlimentacaoFromString(alimentacao);
}

void printAnimal(int animal) {
    switch(animal) {
        case AGUIA:
            (void)printf("aguia\n");
            break;
        case POMBA:
            (void)printf("pomba\n");
            break;
        case HOMEM:
            (void)printf("homem\n");
            break;
        case VACA:
            (void)printf("vaca\n");
            break;
        case PULGA:
            (void)printf("pulga\n");
            break;
        case LAGARTA:
            (void)printf("lagarta\n");
            break;
        case SANGUESSUGA:
            (void)printf("sanguessuga\n");
            break;
        case MINHOCA:
            (void)printf("minhoca\n");
            break;
        default:
            (void)printf("indefinido\n");
    }
}

int main(int argv, char** argc) {
    int animal;
    char vertebrado[MAX_TAM_STRING];
    char tipo[MAX_TAM_STRING];
    char alimentacao[MAX_TAM_STRING];

    (void)scanf("%s %s %s", vertebrado, tipo, alimentacao);
    animal = getAnimalFromStrings(vertebrado, tipo, alimentacao);
    printAnimal(animal);
    return 0;
}