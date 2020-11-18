
#include "lsystem.h"
#include <stack>
#include <memory>
#include <iostream>

std::string LindenmayerSystemDeterministic::expandSymbol(unsigned char const& sym) {
    /*============================================================
        TODO 1.1
        For a given symbol in the sequence, what should it be replaced with after expansion?

        You may find useful:
            map.find: Iterator to an element with key equivalent to key. If no such element is found, past-the-end (see end()) iterator is returned.
            http://en.cppreference.com/w/cpp/container/unordered_map/find
    */

    std::string new_sym = "";

    auto search = rules.find(sym);
    if (search != rules.end()) {
           new_sym = search ->second;
       } else {
        new_sym = {char(sym)};
       }

    return new_sym; // this constructs string from char
    
}

std::string LindenmayerSystem::expandOnce(std::string const& symbol_sequence) {
    /*============================================================
        TODO 1.2
        Perform one iteration of grammar expansion on `symbol_sequence`.
        Use the expandSymbol method
    */
    std::string new_sequence = "";

    for (auto it = symbol_sequence.begin(); it != symbol_sequence.end(); it++)
    {
        new_sequence.append(expandSymbol(*it));
    }

    return new_sequence;

}

std::string LindenmayerSystem::expand(std::string const& initial, uint32_t num_iters) {
    /*============================================================
        TODO 1.3
        Perform `num_iters` iterations of grammar expansion (use expandOnce)
    */

    std::string symbol_sequence = initial;

    for(uint32_t i = 0; i < num_iters; ++i)
    {
        symbol_sequence = expandOnce(symbol_sequence);
    }

    return symbol_sequence;
}

std::vector<Segment> LindenmayerSystem::draw(std::string const& symbols) {
    std::vector<Segment> lines; // this is already initialized as empty vector
    /*============================================================
        TODO 2
        Build line segments according to the sequence of symbols
        The initial position is (0, 0) and the initial direction is "up" (0, 1)
        Segment is std::pair<vec2, vec2>

        you can create a Segment as {p1, p2}, where p1 and p2 are vec2, e.g.:
        lines.push_back({p1, p2});

        You may also find std::stack useful:

        https://en.cppreference.com/w/cpp/container/stack

        There also is a mat2 class in utils/vec.* you may find useful for
        implementing rotations.
    */

    //============================================================

    std::stack<std::pair<vec2, vec2>> current_state;
    vec2 current_point = vec2(0, 0);
    vec2 current_dir = vec2(0,1);
    vec2 tmp_point = vec2(0,0);

    double rotation_angle_rad = deg2rad(rotation_angle_deg);


    for (auto it = symbols.begin(); it != symbols.end(); it++)
    {
        switch (*it) {
        case '[':
            current_state.push({current_point,current_dir});
            break;

        case ']':
            std::tie(current_point, current_dir) = current_state.top();
            current_state.pop();
            break;

        case '+':
            current_dir = mat2(cos(rotation_angle_rad), -sin(rotation_angle_rad),
                               sin(rotation_angle_rad), cos(rotation_angle_rad))
                    * current_dir;
            break;

        case '-':
            current_dir = mat2(cos(-rotation_angle_rad), -sin(-rotation_angle_rad),
                               sin(-rotation_angle_rad), cos(-rotation_angle_rad))
                    * current_dir;
            break;

        case 'F':
            tmp_point = current_point;
            current_point = current_point + normalize(current_dir);
            lines.push_back({tmp_point, current_point});
            break;

        default :
            tmp_point = current_point;
            current_point = current_point + normalize(current_dir);
            lines.push_back({tmp_point, current_point});
            break;

        }
    }


    return lines;
}

std::string LindenmayerSystemStochastic::expandSymbol(unsigned char const& sym) {
    /*============================================================
        TODO 4
        For a given symbol in the sequence, what should it be replaced with after expansion?
        (stochastic case)

        Use dice.roll() to get a random number between 0 and 1
    */
    
    return {char(sym)};
}

void LindenmayerSystemDeterministic::addRuleDeterministic(unsigned char sym, std::string const& expansion) {
    rules[sym] = expansion;
}

void LindenmayerSystemStochastic::addRuleStochastic(unsigned char sym, std::vector<StochasticRule> expansions_with_ps) {
    rules[sym] = expansions_with_ps;
}
