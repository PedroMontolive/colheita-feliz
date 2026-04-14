#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <nlohmann/json.hpp>
#include <iostream>

int main(int argc, char* argv[]){
    if(SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) != 0){
        std::cout << "Error ao inicializar SDL2: " << SDL_GetError() << std::endl;
        return 1;
    }

    std::cout << "SDL2 inicializado com sucesso!" << std::endl;

    SDL_version versao;
    SDL_GetVersion(&versao);

    std::cout << "Versão do SDL2: " << int(versao.major) << "." << int(versao.minor) << "." << int(versao.patch) << std::endl;

    if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)){
        std::cout << "Error ao inicializar SDL2_image: " << IMG_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    std::cout << "SDL2_image (PNG) inicializado com sucesso!" << std::endl;

    if(TTF_Init() != -1){
        std::cout << "Error ao inicializar SDL2_ttf: " << TTF_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    std::cout << "SDL2_ttf inicializado com sucesso!" << std::endl;

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
        std::cout << "Error ao inicializar SDL2_mixer: " << Mix_GetError() << std::endl;
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    std::cout << "SDL2_mixer inicializado com sucesso!" << std::endl;

    nlohmann::json teste;
    teste["jogo"] = "Colheita Feliz";
    teste["versao"] = 1;

    std::cout << "nlohmann::json funcionando! Teste: " << teste.dump(2) << std::endl;

    Mix_CloseAudio();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    std::cout << "\nTodos os subsistemas SDL2 e nlohmann::json foram checados e finalizados corretamente!" << teste.dump(2) << std::endl;

    return 0;
}