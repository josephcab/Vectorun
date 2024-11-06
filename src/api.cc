// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright (c) 2012-2020 Association Prologin <association@prologin.org>

#include "api.hh"

#include <memory>
#include <utility>

// global used in interface.cc
Api* api;

Api::Api(std::unique_ptr<GameState> game_state,
         std::shared_ptr<rules::Player> player)
    : rules::Api<GameState, error>(std::move(game_state), player)
{
    api = this;
}

erreur Api::recuperer_position_joueur(int id_joueur)
{
    // TODO
    abort();
}
int Api::moi()
{
    // TODO
    abort();
}
carte Api::obtenir_carte()
{
    // TODO
    abort();
}
type_case Api::get_type_case(int x, int y)
{
    // TODO
    abort();
}
void Api::afficher_erreur(erreur v)
{
    // TODO
    abort();
}
void Api::afficher_type_case(type_case v)
{
    // TODO
    abort();
}
void Api::afficher_position(position v)
{
    // TODO
    abort();
}
void Api::afficher_carte(carte v)
{
    // TODO
    abort();
}
