
/* void reverse(char *s) {
    if (!s || !*s) return;
    char *g = s, *d = s + strlen(s) - 1;
    while (g < d) {
        char tmp = *g;
        *g++ = *d;
        *d-- = tmp;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* replaceByPosition(const char *str) {
    // Cas : chaîne NULL ou vide
    if (!str || !*str) {
        char *empty = malloc(1);
        if (empty) empty[0] = '\0';
        return empty;
    }
    
    int len = strlen(str);
    // Taille max : chaque lettre donne "26" + espace = 3 octets, +1 pour '\0'
    int max_size = len * 3 + 1;
    char *result = malloc(max_size);
    if (!result) return NULL;
    
    result[0] = '\0';  // Initialise la chaîne vide
    char buffer[10];
    int first = 1;  // Indique si c'est le premier nombre (pas d'espace avant)
    
    for (int i = 0; i < len; i++) {
        char c = tolower(str[i]);
        
        // Ignorer les caractères non alphabétiques
        if (c < 'a' || c > 'z') {
            continue;
        }
        
        // Calculer la position (1 à 26)
        int pos = c - 'a' + 1;
        
        // Ajouter un espace avant sauf pour le premier nombre
        if (!first) {
            strcat(result, " ");
        }
        first = 0;
        
        // Convertir le nombre en chaîne et l'ajouter
        sprintf(buffer, "%d", pos);
        strcat(result, buffer);
    }
    
    return result;
}

def two_sum(nums, target):
    """
    Retourne les indices des deux nombres dont la somme = target.
    """
    seen = {}  # valeur -> indice
    
    for i, val in enumerate(nums):
        complement = target - val
        
        if complement in seen:
            return [seen[complement], i]
        
        seen[val] = i
    
    return []  # Aucune solution (normalement n'arrive pas)


bool isPalindrome(const char *s) {
    if (!s) return true;
    int g = 0, d = strlen(s) - 1;
    while (g < d)
        if (s[g++] != s[d--]) return false;
    return true;
}

int countWords(const char *s) {
    if (!s || !*s) return 0;
    int count = 0, inWord = 0;
    for (int i = 0; s[i]; i++) {
        if (!isspace(s[i])) {
            if (!inWord) { count++; inWord = 1; }
        } else inWord = 0;
    }
    return count;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tes tableaux (fournis)
const char *const morse[55] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", "...-..-", ".--.-.", "...---..."};
const char *const ascii[55] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ".", ",", "?", "'", "!", "/", "(", ")", "&", ":", ";", "=", "+", "-", "_", "\"", "$", "@", "SOS"};

// Cherche un code Morse et retourne son équivalent ASCII
const char* decodeMorseChar(const char* code) {
    for (int i = 0; i < 55; i++) {
        if (strcmp(morse[i], code) == 0) {
            return ascii[i];
        }
    }
    return ""; // Code inconnu
}

// Fonction principale (sans strdup)
char* decodeMorse(const char* morseCode) {
    if (!morseCode) return strdup("");
    
    // Ignorer les espaces au début
    while (*morseCode == ' ') morseCode++;
    
    // Créer une copie modifiable (tableau local)
    int len = strlen(morseCode);
    char buffer[len + 1];
    strcpy(buffer, morseCode);
    
    // Allocation du résultat (taille max = longueur entrée)
    char* result = malloc(len + 1);
    if (!result) return NULL;
    result[0] = '\0';
    
    // Découper par "   " (3 espaces) pour les mots
    char* word = strtok(buffer, "   ");
    
    while (word != NULL) {
        // Découper le mot par " " (1 espace) pour les lettres
        char* letter = strtok(word, " ");
        
        while (letter != NULL) {
            const char* decoded = decodeMorseChar(letter);
            strcat(result, decoded);
            letter = strtok(NULL, " ");
        }
        
        // Ajouter un espace entre les mots
        word = strtok(NULL, "   ");
        if (word != NULL) {
            strcat(result, " ");
        }
    }
    
    return result;
}*/
