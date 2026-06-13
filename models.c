
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
}

import re
import sys

def analyze_email(eml_file):
    with open(eml_file, 'r') as f:
        content = f.read()
    
    # Extract From header
    from_match = re.search(r'^From:\s*(.*?)$', content, re.M)
    sender = from_match.group(1) if from_match else "Unknown"
    
    # Extract all URLs
    urls = re.findall(r'https?://[^\s"\'<>]+', content)
    
    # Suspicious patterns
    suspicious = False
    reasons = []
    
    # Check for domain mismatch
    for url in urls:
        if 'gitiab.com' in url.lower():
            suspicious = True
            reasons.append(f"Fake domain in URL: {url}")
    
    # Check urgency keywords
    urgency_words = ['urgent', 'immediately', 'within 24 hours', 'verify now']
    for word in urgency_words:
        if word in content.lower():
            reasons.append(f"Urgency keyword: {word}")
    
    # Output result (JSON format expected by platform)
    result = {
        "sender": sender,
        "urls": urls,
        "is_phishing": suspicious,
        "reasons": reasons,
        "action": "Report to security team" if suspicious else "Safe"
    }
    
    print(json.dumps(result, indent=2))
    return result

if __name__ == "__main__":
    analyze_email(sys.argv[1])


import os
import time
import psutil
import hashlib
from collections import defaultdict

class RansomwareDetector:
    def __init__(self, watch_dir):
        self.watch_dir = watch_dir
        self.file_hashes = {}  # path -> hash
        self.modification_counts = defaultdict(int)
        
    def get_file_hash(self, filepath):
        """Compute SHA256 hash of file"""
        try:
            with open(filepath, 'rb') as f:
                return hashlib.sha256(f.read()).hexdigest()
        except:
            return None
    
    def scan_directory(self):
        """Scan all files in directory, detect encryption patterns"""
        current_files = {}
        suspicious_pids = set()
        
        for root, dirs, files in os.walk(self.watch_dir):
            for file in files:
                path = os.path.join(root, file)
                
                # Check file extension for encryption artifacts
                if file.endswith(('.encrypted', '.locked', '.crypt')):
                    suspicious_pids.add(self.find_process_accessing_file(path))
                
                # Check rapid modifications
                try:
                    mtime = os.path.getmtime(path)
                    now = time.time()
                    if now - mtime < 2:  # Modified in last 2 seconds
                        self.modification_counts[path] += 1
                        if self.modification_counts[path] > 50:
                            suspicious_pids.add(self.find_process_accessing_file(path))
                except:
                    pass
                
        return list(suspicious_pids)
    
    def find_process_accessing_file(self, filepath):
        """Find which process is accessing a suspicious file"""
        for proc in psutil.process_iter(['pid', 'name']):
            try:
                for item in proc.open_files():
                    if filepath in item.path:
                        return proc.pid
            except:
                pass
        return None
    
    def kill_process(self, pid):
        """Terminate malicious process"""
        try:
            proc = psutil.Process(pid)
            proc.terminate()
            print(f"Killed malicious process PID {pid} ({proc.name()})")
            return True
        except:
            return False
    
    def run(self):
        print(f"Monitoring {self.watch_dir} for ransomware...")
        while True:
            suspicious = self.scan_directory()
            for pid in suspicious:
                if pid:
                    self.kill_process(pid)
            time.sleep(1)

if __name__ == "__main__":
    detector = RansomwareDetector("/var/www/intranet")
    detector.run()


    #include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char ssid[64];
    char bssid[18];
} AccessPoint;

int is_evil_twin(AccessPoint *observed, AccessPoint *known_aps, int known_count) {
    for (int i = 0; i < known_count; i++) {
        // Same SSID but different BSSID = evil twin
        if (strcmp(observed->ssid, known_aps[i].ssid) == 0 &&
            strcmp(observed->bssid, known_aps[i].bssid) != 0) {
            return 1; // Evil twin detected
        }
    }
    return 0;
}

int main() {
    // Legitimate airport APs (SSID, BSSID)
    AccessPoint legitimate[] = {
        {"JFK-Free-WiFi", "00:14:22:33:44:55"},
        {"JFK-Secure",     "00:14:22:33:44:56"},
        {"SFO-Guest",      "AA:BB:CC:DD:EE:01"}
    };
    int legit_count = sizeof(legitimate) / sizeof(legitimate[0]);
    
    // Observed AP from scan
    AccessPoint observed;
    printf("Enter observed SSID: ");
    fgets(observed.ssid, 64, stdin);
    observed.ssid[strcspn(observed.ssid, "\n")] = 0;
    
    printf("Enter observed BSSID (MAC): ");
    fgets(observed.bssid, 18, stdin);
    observed.bssid[strcspn(observed.bssid, "\n")] = 0;
    
    if (is_evil_twin(&observed, legitimate, legit_count)) {
        printf(" EVIL TWIN DETECTED! Do not connect.\n");
        printf("Action: Block connection, notify user.\n");
    } else {
        printf("✓ AP appears legitimate.\n");
    }
    
    return 0;
}




*/
