/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 10:24:41 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/06 19:40:34 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/* 1/ live
 * 10 Cycles. Pas d'OCP. Ne modifie pas le carry. Prend en parametre un direct.
 * Rapporte le joueur designe par le premier parametre comme etant en vie.
 * L'instruction ecrit sur la sortie standard un message du type :
 * "le joueur $player_name ($player_id) a ete rapporte comme etant en vie".
 * Un joueur ne vie que tant qu'au moins un processus effectue un live avec son
 * id, au minimum une fois par CYCLE_TO_DIE. Si le parametre passe ne correspond
 * a l'id d'aucun des joueursm le comportement est indefini (au choix).
*/

/* 2/ ld
 * 5 cycles. A un OCP. Modifie le carry. Adressage restreint. Prend 2 params :
 * (IND / DIR), (REG)
 * Tramsfert direct RAM > Registre. Charge le premier parametre dans le registre
 * passe en second parametre. Si la valeur du premier parametre est egale a
 * zero, alors le carry passe a l'etat un, sinon a zero.
*/

/* 3/ st
 * 5 cycles. A un OCP. Modifie le carry. Adressge restreint. Prend 2 params :
 * (REG), (REG / IND).
 * Transfert direct Registre > RAM / Registre. Charge le contenu du registre
 * passe en premier parametre dans le second parametre. Si la valeur du premmier
 * parametre est egales a zero, alors le carry passe a l'etat 1, sinon a 0.
*/

/* 4/ add
 * Voir add.c
*/

/* 5/ sub
 * Pareil que add
*/

/* 6/ and
 * 6 cycles. A un OCP. Modifie le carry. Adressage restreint. Prend 3 params :
 * (REG / IND / DIR), (REG / IND / DIR), (REG).
 * Effectue un AND logique (&)(Verifie que toutes les conditions sont realisees)
 * entre les deux premier parametres et stock le resultat dans le troisieme
 * parametre. Si la valeur resultante est 0, le carry passe a 1, sinon a 0.
*/

/* 7/ or
 * Exactement pareil que and, mais avec un OU logique (|)(Verifie que l'une des
 * conditions est realisee).
*/

/* 8/ xor
 *	Pareil que or mais en verifiant que une et seulement une des conditions est
 *	realisee.
*/

/* 9/ zjmp
 * 20 Cycles. Pas d'OCP. Adressage non restreint. Ne modifie pas le carry.
 * Prend 1 param : (DIR sur 2 octets).
 * Saute a l'adresse passe en parametre si le carry est a l'etat 1. L'adresse
 * devient alors celle de la prochaine instruction. Si le carry est a 0, rien ne
 * se passe et le flot continue normalement jusau'a l'instruction suivante.
 * Rien ne precise si l'instruction consomme la totalite de ses cycles dans ce
 * cas.
*/

/* 10/ ldi
 * 25 cycles. A un OCP. Modifie le carry. Adressage restreint. Prend 3 params :
 * (REG / IND / DIR), (REG / DIR sur 2 octets), (REG).
 * Transfert indirect RAM > Registre. Charge la valeur a l'adresse resultant de
 * l'addition des deux premiers prametres dans le registre passe en troisieme
 * parametre. Si cette valeur == 0, alors le carry passe a 1, et sinon a 0.
*/

/* 11/ sti
 * 25 Cycles. A un OCP. Adressage restreint. Modifie le carry. Prend 3 params :
 * (REG), (REG / IND / DIR sur 2 octets), (REG / DIR sur 2 octets).
 * Transfert indirect REgistre > RAM. Charge la valeur du contenu dans le
 * registre passe en premier parametre a l'adresse resultante de l'addition des
 * deux derniers parametres. Si cette valeur == 0, le carry passe a 1, sinon a
 * 0.
*/

/* 12/ fork
 * 800 cycles. Pas d'OCP. Adressage restreint. Ne modifie pas le carry.
 * Prend 1 param : (DIR sur 2 octets).
 * Genere un nouveau processus a l'adresse passee en parametre par copie du
 * processus appelant. Le nouveau processus garde donc l'etat de tout les
 * registres et du carry. Seul le pc differe (sauf dans le cas d'un fork %0).
*/

/* 13/ lld
 * 10 Cycles. A un OCP. Adressage non restreint. Modifie le carry. Prend 2
 * params : (IND / DIR), (REG).
 * Pareil que ld mais sans restriction de l'adressage.
*/

/* 14/ lldi
 * 50 cycles. A un OCP. Adressage non restreint. Modifie le carry. Prend 3
 * params : (REG / IND / DIR sur 2 octets), (REG / DIR sur 2 octets), (REG).
 * Pareil que ldi mais sans restriction de l'adressage.
*/

/* 15/ lfork
 * 1000 cycles. Pas d'OCP. Adressage non restreint. Ne modifie pas le carry.
 * Prend 1 param : (DIR sur 2 octets).
 * Pareil que fork mais sans restriction de l'adressage.
*/

/* 16/ aff
 * 2 Cycles. A un OCP. Pas d'adressage. Modifie le carry. Prend 1 param : (REG).
 * Affiche a l'ecran le char correspondant a la valeur du registre passe en
 * parametre, modulo 256. Si ce char est NULL, alors le carry passe a 1, sinon
 * a 0. A nous de choisir le formatage de la sortie ecran. CETTE INSTRUCTION NE
 * SERT A RIEN.
*/
