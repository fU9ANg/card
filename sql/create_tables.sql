# SQL-Front 5.1  (Build 4.16)

/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE */;
/*!40101 SET SQL_MODE='' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES */;
/*!40103 SET SQL_NOTES='ON' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;


# Host: 127.0.0.1 Database: card_db
# ------------------------------------------------------
# Server version 5.5.29-0ubuntu0.12.04.1

DROP DATABASE IF EXISTS `card_db`;
CREATE DATABASE `card_db` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `card_db`;

# ======================================================
#
# Source for table player (玩家信息原始表)
#
DROP TABLE IF EXISTS `player`;
CREATE TABLE `player` (
    `xxx` int(11) NOT NULL AUTO_INCREMENT, # 记录ID
    `xxx` int(11) NOT NULL, # 玩家ID
    `xxx` int(11) NOT NULL, # 账号
    `xxx` int(11) NOT NULL, # 密码
    `xxx` int(20) NOT NULL, # 门派名
    `xxx` int(11) NOT NULL, # 元宝数量
    `xxx` int(11) NOT NULL, # 银子数量
    `xxx` int(11) NOT NULL, # 体力
    `xxx` int(11) NOT NULL, # 气力
    `xxx` int(11) NOT NULL, # 门派等级
    `xxx` int(11) NOT NULL, # VIP等级
    `xxx` int(11) NOT NULL, # 上阵数
    `xxx` int(11) NOT NULL, # 上阵第一位弟子
    `xxx` int(11) NOT NULL, # 上阵第二位弟子
    `xxx` int(11) NOT NULL, # 上阵第三位弟子
    `xxx` int(11) NOT NULL, # 上阵第四位弟子
    `xxx` int(11) NOT NULL, # 上阵第五位弟子
    `xxx` int(11) NOT NULL, # 上阵第六位弟子
    `xxx` int(11) NOT NULL, # 上阵第七位弟子
    `xxx` int(11) NOT NULL, # 上阵第八位弟子
    `xxx` int(11) NOT NULL, # 气势

    PRIMARY KEY (`id`)
)   ENGINE=InnoDB DEFAULT CHARSET=utf8;

# ======================================================
#
# Source for table character (卡片人物原始表)
#
DROP TABLE IF EXISTS `character`;
CREATE TABLE `character` (
    `xxx` int(11) NOT NULL, # 记录ID
    `xxx` int(11) NOT NULL, # 人物ID
    `xxx` int(11) NOT NULL, # 卡名
    `xxx` int(11) NOT NULL, # 基本血
    `xxx` int(11) NOT NULL, # 基本攻
    `xxx` int(11) NOT NULL, # 基本防
    `xxx` int(11) NOT NULL, # 基本内
    `xxx` int(11) NOT NULL, # 基本潜力
    `xxx` int(11) NOT NULL, # 血成长值
    `xxx` int(11) NOT NULL, # 攻成长值
    `xxx` int(11) NOT NULL, # 防成长值
    `xxx` int(11) NOT NULL, # 内成长值
    `xxx` int(11) NOT NULL, # 潜力成长值
    `xxx` int(11) NOT NULL, # 人物缘名称1
    `xxx` int(11) NOT NULL, # 条件1
    `xxx` int(11) NOT NULL, # 结果1
    `xxx` int(11) NOT NULL, # 人物缘名称2
    `xxx` int(11) NOT NULL, # 条件2
    `xxx` int(11) NOT NULL, # 结果2
    `xxx` int(11) NOT NULL, # 人物缘名称3
    `xxx` int(11) NOT NULL, # 条件3
    `xxx` int(11) NOT NULL, # 结果3
    `xxx` int(11) NOT NULL, # 人物缘名称4
    `xxx` int(11) NOT NULL, # 条件4
    `xxx` int(11) NOT NULL, # 结果4
    `xxx` int(11) NOT NULL, # 人物缘名称5
    `xxx` int(11) NOT NULL, # 条件5
    `xxx` int(11) NOT NULL, # 结果5
    `xxx` int(11) NOT NULL, # 人物缘名称6
    `xxx` int(11) NOT NULL, # 条件6
    `xxx` int(11) NOT NULL, # 结果6

    `xxx` int(11) NOT NULL, # 身价
    `xxx` int(11) NOT NULL, # 身价成长
    `xxx` int(11) NOT NULL, # 天赋武功
    `xxx` int(11) NOT NULL, # 弟子经验成长值
    `xxx` int(11) NOT NULL, # 升级后需要的魂魄数量
    `xxx` int(11) NOT NULL, # 人物详细描述

    PRIMARY KEY (`xxx`)
)   ENGINE=InnoDB DEFAULT CHARSET=utf8;

# ======================================================
#
# Source for table equipment (装备[兵器，服装，饰品])
#
DROP TABLE IF EXISTS `equipment`;
CREATE TABLE `equipment` (
    `xxx` int(11) NOT NULL, # 记录ID
    `xxx` int(11) NOT NULL, # 装备ID
    `xxx` int(11) NOT NULL, # 装备类型ID
    `xxx` int(11) NOT NULL, # 装备名称
    `xxx` int(11) NOT NULL, # 品质ID
    `xxx` int(11) NOT NULL, # 原始等级
    `xxx` int(11) NOT NULL, # 原始攻加成
    `xxx` int(11) NOT NULL, # 原始防加成
    `xxx` int(11) NOT NULL, # 原始血加成
    `xxx` int(11) NOT NULL, # 原始内加成
    `xxx` int(11) NOT NULL, # 攻成长值
    `xxx` int(11) NOT NULL, # 防成长值
    `xxx` int(11) NOT NULL, # 血成长值
    `xxx` int(11) NOT NULL, # 内成长值
    `xxx` int(11) NOT NULL, # 身价
    `xxx` int(11) NOT NULL, # 身价成长值
    `xxx` int(11) NOT NULL, # 简介
    PRIMARY KEY (`xxx`)
)   ENGINE=InnoDB DEFAULT CHARSET=utf8;

# ======================================================
#
# Source for table xxxtable (武功原始表)
#
DROP TABLE IF EXISTS `xxxtable`;
CREATE TABLE `xxxtable` (
    `xxx` int(11) NOT NULL, # 记录ID
    `xxx` int(11) NOT NULL, # 武功ID
    `xxx` int(11) NOT NULL, # 武功名称
    `xxx` int(11) NOT NULL, # 品质ID
    `xxx` int(11) NOT NULL, # 原始等级
    `xxx` int(11) NOT NULL, # 原始攻加成(%)
    `xxx` int(11) NOT NULL, # 原始防加成(%)
    `xxx` int(11) NOT NULL, # 原始血加成(%)
    `xxx` int(11) NOT NULL, # 原始内加成(%)
    `xxx` int(11) NOT NULL, # 攻成长值(%)
    `xxx` int(11) NOT NULL, # 防成长值(%)
    `xxx` int(11) NOT NULL, # 血成长值(%)
    `xxx` int(11) NOT NULL, # 内成长值(%)
    `xxx` int(11) NOT NULL, # 单体伤害强度
    `xxx` int(11) NOT NULL, # 单体伤害成长值
    `xxx` int(11) NOT NULL, # 群体伤害强度
    `xxx` int(11) NOT NULL, # 群体伤害成长值
    `xxx` int(11) NOT NULL, # 身价
    `xxx` int(11) NOT NULL, # 身价成长值
    `xxx` int(11) NOT NULL, # 需要的残章数量
    `xxx` int(11) NOT NULL, # 简介
    PRIMARY KEY (`xxx`)
)   ENGINE=InnoDB DEFAULT CHARSET=utf8;

# ======================================================
#
# Source for table experience (等级经验/威望原子表)
#
DROP TABLE IF EXISTS `experience`;
CREATE TABLE `experience` (
    `xxx` int(11) NOT NULL, # 记录ID
    `xxx` int(11) NOT NULL, # 等级
    `xxx` int(11) NOT NULL, # 需要的威望
    PRIMARY KEY (`xxx`)
)   ENGINE=InnoDB DEFAULT CHARSET=utf8;

# ======================================================
#
# Source for table blood (血口决原子表)
#
DROP TABLE IF EXISTS `blood`;
CREATE TABLE `blood` (
    `xxx` int(11) NOT NULL, # 记录ID
    `xxx` int(11) NOT NULL, # 等级
    `xxx` int(11) NOT NULL, # 血加成
    `xxx` int(11) NOT NULL, # 需要的魂魄数量
    PRIMARY KEY (`xxx`)
)   ENGINE=InnoDB DEFAULT CHARSET=utf8;

# ======================================================
#
# Source for table attack (攻口决原子表)
#
DROP TABLE IF EXISTS `attack`;
CREATE TABLE `attack` (
    `xxx` int(11) NOT NULL, # 记录ID
    `xxx` int(11) NOT NULL, # 等级
    `xxx` int(11) NOT NULL, # 攻加成
    `xxx` int(11) NOT NULL, # 需要的魂魄数量
    PRIMARY KEY (`xxx`)
)   ENGINE=InnoDB DEFAULT CHARSET=utf8;

# ======================================================
#
# Source for table xxx (防口决原子表)
#
DROP TABLE IF EXISTS `xxx`;
CREATE TABLE `xxx` (
    `xxx` int(11) NOT NULL, # 记录ID
    `xxx` int(11) NOT NULL, # 等级
    `xxx` int(11) NOT NULL, # 防加成
    `xxx` int(11) NOT NULL, # 需要的魂魄数量
    PRIMARY KEY (`xxx`)
)   ENGINE=InnoDB DEFAULT CHARSET=utf8;

# ======================================================
#
# Source for table xxx (内口决原子表)
#
DROP TABLE IF EXISTS `xxx`;
CREATE TABLE `xxx` (
    `xxx` int(11) NOT NULL, # 记录ID
    `xxx` int(11) NOT NULL, # 等级
    `xxx` int(11) NOT NULL, # 内加成
    `xxx` int(11) NOT NULL, # 需要的魂魄数量
    PRIMARY KEY (`xxx`)
)   ENGINE=InnoDB DEFAULT CHARSET=utf8;

# ======================================================
#
# Source for table xxx (拥有的弟子表)
#
DROP TABLE IF EXISTS `xxx`;
CREATE TABLE `xxx` (
    `xxx` int(11) NOT NULL, # 记录ID
    `xxx` int(11) NOT NULL, # 拥有的弟子ID
    `xxx` int(11) NOT NULL, # 当前等级
    `xxx` int(11) NOT NULL, # 当前身价
    PRIMARY KEY (`xxx`)
)   ENGINE=InnoDB DEFAULT CHARSET=utf8;

# ======================================================
#
# Source for table xxx (拥有的装备表)
#
DROP TABLE IF EXISTS `xxx`;
CREATE TABLE `xxx` (
    `xxx` int(11) NOT NULL, # 记录ID
    `xxx` int(11) NOT NULL, # 拥有的装备ID
    `xxx` int(11) NOT NULL, # 当前等级
    `xxx` int(11) NOT NULL, # 当前身价
    PRIMARY KEY (`xxx`)
)   ENGINE=InnoDB DEFAULT CHARSET=utf8;

# ======================================================
#
# Source for table xxx (江湖主关卡原子表)
#
DROP TABLE IF EXISTS `xxx`;
CREATE TABLE `xxx` (
    `xxx` int(11) NOT NULL, # 记录ID
    `xxx` int(11) NOT NULL, # 关卡ID
    `xxx` int(11) NOT NULL, # 关卡名称
    `xxx` int(11) NOT NULL, # 关卡在江湖中的顺序号
    `xxx` int(11) NOT NULL, # 描述
    PRIMARY KEY (`xxx`)
)   ENGINE=InnoDB DEFAULT CHARSET=utf8;

# ======================================================
#
# Source for table resource (江湖子关卡原子表)
#
DROP TABLE IF EXISTS `xxx`;
CREATE TABLE `xxx` (
    `xxx` int(11) NOT NULL, # 记录ID
    `xxx` int(11) NOT NULL, # 子关卡ID
    `xxx` int(11) NOT NULL, # 关卡名称
    `xxx` int(11) NOT NULL, # BOSS名称
    `xxx` int(11) NOT NULL, # BOSS图片
    `xxx` int(11) NOT NULL, # 需要的体力消耗
    `xxx` int(11) NOT NULL, # 每日最多挑战次数
    `xxx` int(11) NOT NULL, # 建议等级
    `xxx` int(11) NOT NULL, # 胜利获得的威望
    `xxx` int(11) NOT NULL, # 胜利获得的银子数量
    `xxx` int(11) NOT NULL, # 有机率获得的装备／武功ID 1
    `xxx` int(11) NOT NULL, # 有机率获得的装备／武功ID 2
    `xxx` int(11) NOT NULL, # 有机率获得的装备／武功ID 3
    PRIMARY KEY (`xxx`, `yyy`)
)   ENGINE=InnoDB DEFAULT CHARSET=utf8;

# ======================================================
#
# Source for table xxx (真气原子表)
#

DROP TABLE IF EXISTS `xxx`;
CREATE TABLE `xxx` (
    `xxx` int(11) NOT NULL, # 记录ID
    `xxx` int(11) NOT NULL, # 真气ID
    `xxx` int(11) NOT NULL, # 真气名称
    `xxx` int(11) NOT NULL, # 真气品质
    `xxx` int(11) NOT NULL, # 效果
    PRIMARY KEY (`xxx`)
)   ENGINE=InnoDB DEFAULT CHARSET=utf8;

# ======================================================
#
# Source for table xxx (品质原子表)
#

DROP TABLE IF EXISTS `xxx`;
CREATE TABLE `xxx` (
    `xxx` int(11) NOT NULL, # 记录ID
    `xxx` int(11) NOT NULL, # 品质ID
    `xxx` int(11) NOT NULL, # 品质名称
    PRIMARY KEY (`xxx`)
)   ENGINE=InnoDB DEFAULT CHARSET=utf8;

# ======================================================
#
# Source for table xxx (VIP原子表)
#

DROP TABLE IF EXISTS `xxx`;
CREATE TABLE `xxx` (
    `xxx` int(11) NOT NULL, # 记录ID
    `xxx` int(11) NOT NULL, # VIP_ID
    `xxx` int(11) NOT NULL, # VIP名称
    `xxx` int(11) NOT NULL, # 万中选一甲之比例
    `xxx` int(11) NOT NULL, # 万中选一乙之比例
    `xxx` int(11) NOT NULL, # 百中选一甲之比例
    `xxx` int(11) NOT NULL, # 百中选一乙之比例
    `xxx` int(11) NOT NULL, # 百中选一丙之比例
    `xxx` int(11) NOT NULL, # 十中选一乙之比例
    `xxx` int(11) NOT NULL, # 十中选一丙之比例
    `xxx` int(11) NOT NULL, # 十中选一丁之比例
    `xxx` int(11) NOT NULL, # 箱子出甲兵器之比例
    `xxx` int(11) NOT NULL, # 箱子出甲服装之比例
    `xxx` int(11) NOT NULL, # 箱子出甲饰品之比例
    `xxx` int(11) NOT NULL, # 箱子出甲武功之比例
    `xxx` int(11) NOT NULL, # 箱子出乙兵器之比例
    `xxx` int(11) NOT NULL, # 箱子出乙服装之比例
    `xxx` int(11) NOT NULL, # 箱子出乙饰品之比例
    `xxx` int(11) NOT NULL, # 箱子出乙武功之比例
    `xxx` int(11) NOT NULL, # 箱子出丙兵器之比例
    `xxx` int(11) NOT NULL, # 箱子出丙服装之比例
    `xxx` int(11) NOT NULL, # 箱子出丙饰品之比例
    `xxx` int(11) NOT NULL, # 箱子出丙武功之比例
    `xxx` int(11) NOT NULL, # 箱子出丁兵器之比例
    `xxx` int(11) NOT NULL, # 箱子出丁服装之比例
    `xxx` int(11) NOT NULL, # 箱子出丁饰品之比例
    `xxx` int(11) NOT NULL, # 箱子出丁武功之比例
    PRIMARY KEY (`xxx`)
)   ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
