-- --------------------------------------------------------
-- Hôte :                        localhost
-- Version du serveur:           5.7.24 - MySQL Community Server (GPL)
-- SE du serveur:                Win64
-- HeidiSQL Version:             10.2.0.5599
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

-- Listage des données de la table loki.failed_jobs : ~0 rows (environ)
/*!40000 ALTER TABLE `failed_jobs` DISABLE KEYS */;
/*!40000 ALTER TABLE `failed_jobs` ENABLE KEYS */;

-- Listage des données de la table loki.formations : ~0 rows (environ)
/*!40000 ALTER TABLE `formations` DISABLE KEYS */;
INSERT INTO `formations` (`id`, `fmt_name`) VALUES
	(1, 'Informatique'),
	(2, 'Biologie'),
	(3, 'Physique');
/*!40000 ALTER TABLE `formations` ENABLE KEYS */;

-- Listage des données de la table loki.users : ~1 rows (environ)
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` (`id`, `firstname`, `name`, `email`, `email_verified_at`, `password`, `remember_token`, `created_at`, `updated_at`, `formation_id`, `role_id`) VALUES
	(2, 'Rabat', 'Cyril', 'rc@gmail.com', NULL, '$2y$10$LmTbeP9lwfTG3U0FnEb.4ejNx8Ek.zcAgpQ9Jb5BXwcE0mVDu/o06', NULL, '2020-12-09 16:31:48', '2020-12-09 16:31:48', 1, 2),
	(3, 'Dupont', 'Corentin', 'dc@gmail.com', NULL, '$2y$10$iV2Bxx4qJQMuiMvNpFa11uznX1ZWrQ8UivmK.D9RN8R371zxnTT0G', NULL, '2020-12-09 16:33:01', '2020-12-09 16:40:43', 1, 4),
	(4, 'Lacroix', 'Owen', 'lo@gmail.com', NULL, '$2y$10$b6eaj/H7XrAaFDhhyCshVuO/bio39ghFIh6Repqtrzv49CLyO6sKS', NULL, '2020-12-09 16:36:00', '2020-12-09 16:43:08', 1, 4),
	(5, 'Patrice', 'Kevin', 'pk@gmail.com', NULL, '$2y$10$MlvbYlBNIpQj75TxowQPmOzhjWMOiGlZRFr4bvYg6hnSWINpd8u2y', NULL, '2020-12-09 16:36:31', '2020-12-09 16:36:31', 1, 4),
	(6, 'Delisle', 'Pierre', 'dp@gmail.com', NULL, '$2y$10$mEU0tEV7AsxadxP75Mf63.w.kYpQ.WMZ2BxkrBmMI4nCgVEeacPwq', NULL, '2020-12-09 16:37:44', '2020-12-09 16:37:44', 1, 3),
	(7, 'Alfonso', 'Vincent', 'av@gmail.com', NULL, '$2y$10$9j.vldexyhwkkpMzA3KLh.JwOriUZSqRm0dIUMv37xfv85x8EGpOu', NULL, '2020-12-09 16:38:56', '2020-12-09 16:38:56', 3, 4),
	(8, 'Hervelin', 'Bryan', 'hb@gmail.com', NULL, '$2y$10$WHnAJaQ1FLQOClVk0ZWB9upQo.6JWGoufFxKfiA06RGi2f0cqgPLO', NULL, '2020-12-09 16:47:32', '2020-12-09 16:47:32', 1, 4),
	(9, 'Cornec', 'Benjamin', 'cb@gmail.com', NULL, '$2y$10$xcG7.P4PtykURRvqjugXgO1jZjpyrwSDZsjjye.6eRsblvkbsMJcu', NULL, '2020-12-09 16:48:09', '2020-12-09 16:48:09', 1, 4);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;

-- Listage des données de la table loki.groups : ~0 rows (environ)
/*!40000 ALTER TABLE `groups` DISABLE KEYS */;
INSERT INTO `groups` (`id`, `grp_name`, `type_education_id`, `formation_id`, `year_id`) VALUES
	(1, 'S3F3', 1, 1, 2),
	(2, 'S3F3A', 2, 1, 2),
	(3, 'S3F3B', 2, 1, 2),
	(4, 'S5O6', 1, 1, 3),
	(5, 'S5O6A', 2, 1, 3);
/*!40000 ALTER TABLE `groups` ENABLE KEYS */;

-- Listage des données de la table loki.password_resets : ~0 rows (environ)
/*!40000 ALTER TABLE `password_resets` DISABLE KEYS */;
/*!40000 ALTER TABLE `password_resets` ENABLE KEYS */;

-- Listage des données de la table loki.presences : ~0 rows (environ)
/*!40000 ALTER TABLE `presences` DISABLE KEYS */;
/*!40000 ALTER TABLE `presences` ENABLE KEYS */;

-- Listage des données de la table loki.roles : ~4 rows (environ)
/*!40000 ALTER TABLE `roles` DISABLE KEYS */;
/*!40000 ALTER TABLE `roles` ENABLE KEYS */;

-- Listage des données de la table loki.subjects : ~0 rows (environ)
/*!40000 ALTER TABLE `subjects` DISABLE KEYS */;
INSERT INTO `subjects` (`id`, `sbj_name`, `formation_id`, `year_id`) VALUES
	(1, 'Info0303', 1, 2),
	(2, 'Info0501', 1, 3);
/*!40000 ALTER TABLE `subjects` ENABLE KEYS */;

-- Listage des données de la table loki.sessions : ~0 rows (environ)
/*!40000 ALTER TABLE `sessions` DISABLE KEYS */;
INSERT INTO `sessions` (`id`, `date_start`, `date_end`, `user_id`, `group_id`, `subject_id`) VALUES
	(1, '2020-12-14 16:15:00', '2020-12-14 18:15:00', 2, 1, 1),
	(2, '2020-12-14 08:00:00', '2020-12-14 10:00:00', 2, 3, 1),
	(3, '2020-12-15 10:15:00', '2020-12-15 12:15:00', 6, 4, 2),
	(4, '2020-12-16 08:00:00', '2020-12-16 10:00:00', 6, 5, 2);
/*!40000 ALTER TABLE `sessions` ENABLE KEYS */;

-- Listage des données de la table loki.states : ~4 rows (environ)
/*!40000 ALTER TABLE `states` DISABLE KEYS */;
/*!40000 ALTER TABLE `states` ENABLE KEYS */;

-- Listage des données de la table loki.type_educations : ~2 rows (environ)
/*!40000 ALTER TABLE `type_educations` DISABLE KEYS */;
/*!40000 ALTER TABLE `type_educations` ENABLE KEYS */;

-- Listage des données de la table loki.users_groups : ~0 rows (environ)
/*!40000 ALTER TABLE `users_groups` DISABLE KEYS */;
INSERT INTO `users_groups` (`user_id`, `group_id`) VALUES
	(2, 1),
	(3, 1),
	(4, 1),
	(5, 1),
	(2, 2),
	(5, 2),
	(2, 3),
	(3, 3),
	(4, 3),
	(6, 4),
	(8, 4),
	(9, 4),
	(6, 5),
	(8, 5),
	(9, 5);
/*!40000 ALTER TABLE `users_groups` ENABLE KEYS */;

-- Listage des données de la table loki.users_subjects : ~0 rows (environ)
/*!40000 ALTER TABLE `users_subjects` DISABLE KEYS */;
INSERT INTO `users_subjects` (`user_id`, `subject_id`) VALUES
	(2, 1),
	(6, 2);
/*!40000 ALTER TABLE `users_subjects` ENABLE KEYS */;

-- Listage des données de la table loki.years : ~5 rows (environ)
/*!40000 ALTER TABLE `years` DISABLE KEYS */;
/*!40000 ALTER TABLE `years` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
