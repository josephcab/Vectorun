// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright (c) 2012-2020 Association Prologin <association@prologin.org>

#pragma once


/// Largeur maximale de la grille de jeu
#define LARGEUR_MAX 512

/// Hauteur maximale de la grille de jeu
#define HAUTEUR_MAX 512


/// Contient toutes les erreurs pouvant être levées par l'API de jeu
typedef enum error
{
    OK, ///< Aucune erreur survenue
    POSITION_INVALIDE, ///< Position non valide
    MOUVEMENT_INTERDIT, ///< Mouvement non valide. Vous foncez dans un mur !
} error;

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

/// Retourne une dimension de plateau
typedef struct dimension
{
    int dim_x; ///< Dimension de la colonne
    int dim_y; ///< Dimension de la ligne
} dimension;

/// Représente une case de la carte
typedef struct pos_info
{
    type_case contenu; ///< Liste des case de la carte
    position pos; ///< Liste des positions de la carte
} pos_info;
