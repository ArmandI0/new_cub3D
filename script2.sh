#!/bin/bash

# Boucle sur tous les fichiers .c dans le répertoire courant
for file in *_bonus.c
do
    # Supprime "_bonus" de la fin du nom de fichier
    new_file=$(echo "$file" | sed 's/_bonus//')

    # Renomme le fichier en supprimant "_bonus" de la fin du nom de fichier
    mv "$file" "$new_file"
done

