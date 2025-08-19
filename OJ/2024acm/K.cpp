#include <bits/stdc++.h>
using namespace std;

struct Equipment
{
    int type;
    int attack;
    int crit_rate;
    int crit_damage;
};

// 计算装备带来的期望伤害
double calculateExpectedDamage(int base_attack, int base_crit_rate, int base_crit_damage, const Equipment &eq)
{
    int new_attack = base_attack + eq.attack;
    int new_crit_rate = min(100, base_crit_rate + eq.crit_rate);
    int new_crit_damage = base_crit_damage + eq.crit_damage;
    return new_attack * (1 + new_crit_rate / 100.0 * new_crit_damage / 100.0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<Equipment> equipments(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> equipments[i].type >> equipments[i].attack >> equipments[i].crit_rate >> equipments[i].crit_damage;
    }

    // 初始面板属性
    int base_attack = 0;
    int base_crit_rate = 0;
    int base_crit_damage = 0;

    // 按类型分类装备
    unordered_map<int, Equipment> best_equipment;
    for (const auto &eq : equipments)
    {
        if (best_equipment.find(eq.type) == best_equipment.end())
        {
            best_equipment[eq.type] = eq;
        }
        else
        {
            // 比较选择该装备和已有装备哪个带来的期望伤害更高
            double current_damage = calculateExpectedDamage(base_attack, base_crit_rate, base_crit_damage, best_equipment[eq.type]);
            double new_damage = calculateExpectedDamage(base_attack, base_crit_rate, base_crit_damage, eq);
            if (new_damage > current_damage)
            {
                best_equipment[eq.type] = eq;
            }
        }
    }

    // 重新计算选择最优装备后的面板属性
    base_attack = 0;
    base_crit_rate = 0;
    base_crit_damage = 0;
    for (const auto &eq : best_equipment)
    {
        base_attack += eq.second.attack;
        base_crit_rate += eq.second.crit_rate;
        base_crit_damage += eq.second.crit_damage;
    }
    base_crit_rate = min(base_crit_rate, 100);

    // 计算期望伤害
    double expected_damage = base_attack * (1 + base_crit_rate / 100.0 * base_crit_damage / 100.0);

    // 输出结果，保留四位小数
    cout << fixed << setprecision(4) << expected_damage << endl;

    return 0;
}