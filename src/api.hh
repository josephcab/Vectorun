// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright (c) 2012-2020 Association Prologin <association@prologin.org>

#pragma once

#include <memory>
#include <string>
#include <vector>

#include <rules/api.hh>
#include <rules/player.hh>

#include "actions.hh"
#include "constant.hh"
#include "game_state.hh"

/**
 * The methods of this class are exported through 'interface.cc'
 * to be called by the clients
 */
class Api final : public rules::Api<GameState, error>
{
public:
    Api(std::unique_ptr<GameState> game_state,
        std::shared_ptr<rules::Player> player);
    ~Api() {}

    /// Renvoie la position de l'utilisateur
    error recuperer_position_joueur(int id_joueur);

    /// Renvoie son identifiant de joueur
    int moi();

    /// Renvoie son identifiant de joueur
    dimension dimension_carte();

    /// initie un déplacement
    ApiActionFunc<ActionBouger> bouger{this};

    /// Renvoie la carte du jeu
    std::vector<pos_info> obtenir_carte();

    /// initie un déplacement
    type_case get_type_case(int x, int y);

    /// Affiche le contenu d'une valeur de type error
    void afficher_error(error v);

    /// Affiche le contenu d'une valeur de type type_case
    void afficher_type_case(type_case v);

    /// Affiche le contenu d'une valeur de type position
    void afficher_position(position v);

    /// Affiche le contenu d'une valeur de type dimension
    void afficher_dimension(dimension v);

    /// Affiche le contenu d'une valeur de type pos_info
    void afficher_pos_info(pos_info v);

};
