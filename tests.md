# Test a effectuer sur chaque philosophes

- Rester en vie et timestamps cohérent, pas de mélange.
- [ ] 4 410 200 200 *test opti paire*
- [ ] 5 610 200 200 *test opti impaire*
- [ ] 50 610 200 200 *test beaucoup de philo* **uniquement pour philo1**
> Ce test est que pour philo1 car, comme les philos ont une cuillère attribuée chacun
> cela peut poser problème en fonction de l'ordre des philosophes a commencer à manger.
> 
> Cet aléatoire est produit à cause de l'allocation de threads par rapport au threads
> disponible sur le PC hote. Je penses que ce cas se produit a partir du nombre
> de philosophers > nombre de threads disponible celon l'hote.
- [ ] 50 410 200 200 *test beaucoup de philo* **uniquement pour philo2/3**

<br />

- Checker le nombre de repas au total et les messages
apres que les philosophes aient mangés.
Checker le comportement apres la mort.
- [ ] 5 800 200 200 7 *test repas*
- [ ] 5 400 200 200 7 *test mort repas*

<br />

- Checker la mort, son delai et pas de messages apres la mort.
- [ ] 5 400 200 200 *impaire*
- [ ] 4 400 200 200 *paire*
- [ ] 2 400 200 200 *2 philos*
- [ ] 50 2000 1000 1000 *beaucoup de philo*

---
