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

/*!40000 ALTER TABLE `formations` ENABLE KEYS */;

-- Listage des données de la table loki.groups : ~0 rows (environ)
/*!40000 ALTER TABLE `groups` DISABLE KEYS */;
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

-- Listage des données de la table loki.sessions : ~0 rows (environ)
/*!40000 ALTER TABLE `sessions` DISABLE KEYS */;
/*!40000 ALTER TABLE `sessions` ENABLE KEYS */;

-- Listage des données de la table loki.states : ~4 rows (environ)
/*!40000 ALTER TABLE `states` DISABLE KEYS */;
/*!40000 ALTER TABLE `states` ENABLE KEYS */;

-- Listage des données de la table loki.subjects : ~0 rows (environ)
/*!40000 ALTER TABLE `subjects` DISABLE KEYS */;
/*!40000 ALTER TABLE `subjects` ENABLE KEYS */;

-- Listage des données de la table loki.type_educations : ~2 rows (environ)
/*!40000 ALTER TABLE `type_educations` DISABLE KEYS */;
/*!40000 ALTER TABLE `type_educations` ENABLE KEYS */;

-- Listage des données de la table loki.users : ~1 rows (environ)
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` (`id`, `firstname`, `name`, `email`, `email_verified_at`, `password`, `remember_token`, `created_at`, `updated_at`, `formation_id`, `role_id`) VALUES
	(1, 'Sleipnir', 'Odin', 'odin@gmail.com', NULL, '$2y$10$jvaQfrDvY3YDuOX/nE/1K.EMGAiWi9aZlIgXETEjN9RRPTUHcVbS6', NULL, '2020-12-09 16:24:35', '2020-12-09 16:24:35', NULL, 1);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;

-- Listage des données de la table loki.users_groups : ~0 rows (environ)
/*!40000 ALTER TABLE `users_groups` DISABLE KEYS */;
/*!40000 ALTER TABLE `users_groups` ENABLE KEYS */;

-- Listage des données de la table loki.users_subjects : ~0 rows (environ)
/*!40000 ALTER TABLE `users_subjects` DISABLE KEYS */;
/*!40000 ALTER TABLE `users_subjects` ENABLE KEYS */;

-- Listage des données de la table loki.years : ~5 rows (environ)
/*!40000 ALTER TABLE `years` DISABLE KEYS */;
/*!40000 ALTER TABLE `years` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
