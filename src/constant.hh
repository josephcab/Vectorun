// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright (c) 2012-2020 Association Prologin <association@prologin.org>

#pragma once


/// Largeur maximale de la grille de jeu
#define LARGEUR_MAX 512

/// Hauteur maximale de la grille de jeu
#define HAUTEUR_MAX 512


/// Contient toutes les erreurs pouvant être levées par l'API de jeu
typedef enum erreur
{
    OK, ///< Aucune erreur survenue
    POSITION_INVALIDE, ///< Position non valide
} erreur;

/// liste des types de cases du plateau
typedef enum type_case
{
    VIDE, ///< Case vide, sur laquelle il est possible d'aller
    MUR, ///< Case infranchissable
    CASE_INVALIDE, ///< Erreur, cellule inexistante
} type_case;


/// Représente une position
typedef struct position
{
    int x; ///< Coordonnée de la colonne
    int y; ///< Coordonnée de la ligne
} position;

/// Représente l'ensemble de la carte
typedef struct carte
{
    std::vector<type_case> contenu; ///< Liste des case de la carte
    std::vector<position> pos; ///< Liste des positions de la carte
} carte;
