//
// Created by Y.A. on 2017/08/10.
//

#ifndef HUMANITY_BATTLESCENE_CHARACTER_ENEMY_ENEMYSTATUS_H
#define HUMANITY_BATTLESCENE_CHARACTER_ENEMY_ENEMYSTATUS_H

#include <string>

class SDL_Texture;

namespace BattleScene::Character::Enemy {
    class EnemyStatus {
    public:
        virtual void initialize() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;
        virtual void finalize();
        virtual bool isDone();

    protected:
        bool is_done_;
        SDL_Texture* status_img_;

        // size of character image
        // different from the size of combined image data
        int img_width_;
        int img_height_;

        virtual void do_common_init(std::string status_img_path);
    };
}


#endif //HUMANITY_BATTLESCENE_CHARACTER_ENEMY_ENEMYSTATUS_H
