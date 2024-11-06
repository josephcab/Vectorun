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


extern "C" erreur api_recuperer_position_joueur(int id_joueur)
{
    return api->recuperer_position_joueur(id_joueur);
}

extern "C" int api_moi()
{
    return api->moi();
}

extern "C" erreur api_bouger(int id_joueur, int var_x, int var_y)
{
    return api->bouger(id_joueur, var_x, var_y);
}

extern "C" carte api_obtenir_carte()
{
    return api->obtenir_carte();
}

extern "C" type_case api_get_type_case(int x, int y)
{
    return api->get_type_case(x, y);
}

extern "C" void api_afficher_erreur(erreur v)
{
    api->afficher_erreur(v);
}

extern "C" void api_afficher_type_case(type_case v)
{
    api->afficher_type_case(v);
}

extern "C" void api_afficher_position(position v)
{
    api->afficher_position(v);
}

extern "C" void api_afficher_carte(carte v)
{
    api->afficher_carte(v);
}

std::ostream& operator<<(std::ostream& os, erreur v)
{
    switch (v)
    {
    case OK:
        os << "OK";
        break;
    case POSITION_INVALIDE:
        os << "POSITION_INVALIDE";
        break;
    }
    return os;
}

extern "C" void api_afficher_erreur(erreur v)
{
    std::cerr << v << std::endl;
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

extern "C" void api_afficher_type_case(type_case v)
{
    std::cerr << v << std::endl;
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

extern "C" void api_afficher_position(position v)
{
    std::cerr << v << std::endl;
}
std::ostream& operator<<(std::ostream& os, carte v)
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

extern "C" void api_afficher_carte(carte v)
{
    std::cerr << v << std::endl;
}
