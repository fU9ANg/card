
enum eQuality
{
    EQ_A = 1,   // 甲
    EQ_B = 2,   // 乙
    EQ_C = 3,   // 丙
    EQ_D = 4,   // 丁
};

class CSkill
{
    private:
};

class CCharacter
{
    private:
        string      m_char_name;    // 人物名称
        int         m_b_blood;      // 基本血
        int         m_b_attack;     // 基本攻
        int         m_b_defense;    // 基本防
        int         m_b_forces;     // 基本内
        int         m_b_potential;  // 基本潜力
        int         m_b_level;      // 基本等级
        int         m_up_blood;     // 基本血
        int         m_up_attack;    // 基本攻
        int         m_up_defense;   // 基本防
        int         m_up_forces;    // 基本内
        int         m_up_potential; // 基本潜力
        int         m_worth;        // 身价
        CSkill*     m_skill;        // 天赋武功
        int         m_soul;         // 魂魄
        string      m_desc;         // 描述
        eQuality    m_quality;      // 品质
};

class CCharacterManager
{
    public:
        std::map<CCharacter*> CHARACTERMAP;
    public:
        int             init_characters (...);
        CCharacter*     get_character (...);
        int             set_character (CCharacter* c);
    private:
        CHARACTERMAP    m_char_map;
};

class CHero
{
    private:
        string      m_hero_name;    // 英雄人物名称
        int         m_blood;        // 血
        int         m_attack;       // 攻
        int         m_defense;      // 防
        int         m_forces;       // 内
        int         m_potential;    // 潜力
        int         m_level;        // 等级
        CCharacter* m_character;
};

class CPlayer
{
    private:
        int         m_player_id;    // 玩家ID
        string      m_dep_name;     // 门派名称
        int         m_dep_level;    // 门派等级
        string      m_password;     // 密码
        int         m_glod;         // 元宝
        int         m_silver;       // 银量
        int         m_strength;     // 体力
        int         m_energy;       // 气力
        int         m_momentum;     // 气势
        int         m_curr_momentum;// 当前已有的气势
        int         m_total_char;   // 上阵弟子数
        int         m_curr_char;    // 当前上阵弟子数
};
