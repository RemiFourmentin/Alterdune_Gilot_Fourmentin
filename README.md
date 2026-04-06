# Alterdune_Gilot_Fourmentin
Projet POO C++

J'ai crée les classes Item et Monster, pour les modifier dans l'explorateur des solutions, clique sur Item.h ou Monster.h

Elles sont déjà bien remplies sans quoi j'aurai pas pu faire un affichage pertinent des CSV, dis moi si ca s'affiche bien direct sur ta console.

J'ai un peu la flemme de faire le pseudo code du projet ce soir vu que j'y ai passé une bonne partie de l'aprem mais on voit ça au pire demain,
si tu te chauffes a l'écrire ça me va aussi mais sois bien précis dans ce que font les méthodes, ce qu'elles prennent en paramètres (le moins possible) et ce qu'elles retournent.
Hesite pas a bien segmenter le code en méthodes quitte a ce qu'elles soient toutes petites.

UPDATE:
En codant j'ai réalisé à quel point avoir une classe Action et potentiellement une classe Combat nous simplifierait la vie, ce serait-ce que pour centraliser les méthodes de classes.
Pour l'instant le combat est défini sauvagement en tant que méthode dans le code mais je vais bouger ça rapidement.

Si tu veux, tu peux créer la classe Action qui a comme attribut un joueur et un monstre, tu regardes les différentes actions possibles dans monstrers.csv et tu défini des changements de stats sur le joueur et sur le monstre: HP, HPMAX, ATK, DEF et Mercy(OBLIGATOIRE POUR JOUEUR), sois créatif et affiche un message drôle pour chaque action.
D'ailleurs n'hesite pas à en créer toi même, ex: GOONER -> Jouer.HP += 20, Joueur.ATK -= 10, Monstre.DEF -= 20, message="FAHHHH"
