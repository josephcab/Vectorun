// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright (c) 2012-2020 Association Prologin <association@prologin.org>

#include <iostream>
#include <sstream>
#include <vector>

#include "api.hh"

// from api.cc
extern Api* api;

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& arr)
{
    os << "[";
    typename std::vector<T>::const_iterator it;
    for (it = arr.begin(); it != arr.end(); ++it)
    {
        if (it != arr.begin())
            os << ", ";
        os << *it;
    }
    os << "]";
    return os;
}


extern "C" error api_recuperer_position_joueur(int id_joueur)
{
    return api->recuperer_position_joueur(id_joueur);
}

extern "C" int api_moi()
{
    return api->moi();
}

extern "C" dimension api_dimension_carte()
{
    return api->dimension_carte();
}

extern "C" error api_bouger(int id_joueur, int var_x, int var_y)
{
    return api->bouger(id_joueur, var_x, var_y);
}

extern "C" std::vector<pos_info> api_obtenir_carte()
{
    return api->obtenir_carte();
}

extern "C" type_case api_get_type_case(int x, int y)
{
    return api->get_type_case(x, y);
}

extern "C" void api_afficher_error(error v)
{
    api->afficher_error(v);
}

extern "C" void api_afficher_type_case(type_case v)
{
    api->afficher_type_case(v);
}

extern "C" void api_afficher_position(position v)
{
    api->afficher_position(v);
}

extern "C" void api_afficher_dimension(dimension v)
{
    api->afficher_dimension(v);
}

/* extern "C" void api_afficher_pos_info(pos_info v)
{
    api->afficher_pos_info(v);
}
 */
std::ostream& operator<<(std::ostream& os, error v)
{
    switch (v)
    {
    case OK:
        os << "OK";
        break;
    case POSITION_INVALIDE:
        os << "POSITION_INVALIDE";
        break;
    case MOUVEMENT_INTERDIT:
        os << "MOUVEMENT_INTERDIT";
        break;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, type_case v)
{
    switch (v)
    {
    case VIDE:
        os << "VIDE";
        break;
    case MUR:
        os << "MUR";
        break;
    case CASE_INVALIDE:
        os << "CASE_INVALIDE";
        break;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, position v)
{
    os << "{ ";
    os << "x"
       << "=" << v.x;
    os << ", ";
    os << "y"
       << "=" << v.y;
    os << " }";
    return os;
}

std::ostream& operator<<(std::ostream& os, dimension v)
{
    os << "{ ";
    os << "dim_x"
       << "=" << v.dim_x;
    os << ", ";
    os << "dim_y"
       << "=" << v.dim_y;
    os << " }";
    return os;
}

std::ostream& operator<<(std::ostream& os, pos_info v)
{
    os << "{ ";
    os << "contenu"
       << "=" << v.contenu;
    os << ", ";
    os << "pos"
       << "=" << v.pos;
    os << " }";
    return os;
}
