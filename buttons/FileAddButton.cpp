//
// Created by cilan on 3/31/2017.
//

#include "FileAddButton.h"

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

FileAddButton::FileAddButton(std::vector<std::shared_ptr<Button>>* fileArray, uint16_t width, uint16_t height) : Button() {
    this->texture = &MainMenuTextures::addFileTexture;
    this->updateTexture();

    this->width = width;
    this->height = height;

    this->fileButtons = fileArray;
}

void FileAddButton::clickHandler(sf::RenderWindow& window) {
    std::cout << "derp" << std::endl;
    CancelTextInputButton cancelBtn = CancelTextInputButton("Cancel");
    ConfirmFilenameButton confirmBtn = ConfirmFilenameButton("Confirm");
    TextInput("What is your name?", &cancelBtn, &confirmBtn).loop(window);
    /*this->fileButtons->insert(this->fileButtons->begin() + this->fileButtons->size() - 1, std::make_shared<FileButton>(*fileButtons));
    Data data = Data();
    data.levelid = 1;
    std::string savePath = Locator::getResource()->loadPath("saves/save" + patch::to_string(this->fileButtons->size() - 1));
    std::ofstream saveOut = std::ofstream(savePath, std::ios::out | std::ios::binary);
    saveOut << data;
    saveOut.close();
    position();*/
    // TextInput().loop(&window);
}

void FileAddButton::sHoverHandler(bool first) {
    if (first) {
        this->texture = &MainMenuTextures::highlightedAddFileTexture;
        this->updateTexture();
    }
}

void FileAddButton::sHoverExit() {
    this->texture = &MainMenuTextures::addFileTexture;
    this->updateTexture();
}

void FileAddButton::position() {
    for (uint8_t i = 0; i < fileButtons->size(); i++) {
        std::shared_ptr<Button> fileButton = (*fileButtons)[i];
        const uint16_t oldBtnWidth = (uint16_t) fileButton->getTexture()->getSize().x;
        const uint16_t oldBtnHeight = (uint16_t) fileButton->getTexture()->getSize().y;
        const uint8_t gap = 5;
        const float ratio = (float) oldBtnHeight / oldBtnWidth;
        const float scale = .2;
        const uint16_t btnWidth = (uint16_t) (width * scale);
        const uint16_t btnHeight = (uint16_t) (btnWidth * ratio);
        const uint16_t startY = (uint16_t) ((height - btnHeight) / 2.5);
        const uint16_t startX = gap;
        fileButton->setScale((float) btnWidth / oldBtnWidth, (float) btnHeight / oldBtnHeight);
        fileButton->setPosition(i * btnWidth + (i + 1) * gap + startX, startY);
    }
}
