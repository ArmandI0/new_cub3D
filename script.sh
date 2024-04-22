#!/bin/bash

# Boucle sur tous les fichiers .c dans le répertoire courant
for file in *.c
do
    # Vérifie si le fichier a déjà l'extension "_bonus.c"
    if [[ "$file" != *_bonus.c ]]
    then
        # Renomme le fichier en ajoutant "_bonus" avant l'extension ".c"
        mv "$file" "${file%.*}_bonus.c"
    fi
done