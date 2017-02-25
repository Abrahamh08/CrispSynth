//
// Created by cilan on 1/20/2017.
//

#include "Locator.h"

std::shared_ptr<IResources> Locator::nullService_ = std::make_shared<NullResources>();
std::shared_ptr<IResources> Locator::service_ = std::move(Locator::nullService_);

std::map<std::string, std::string> Locator::defaultConfig = {
        {"fullscreen" , "yes"}
};

boost::filesystem::path Locator::rootPath;

Locator::Locator() {
    Locator::service_.reset();
}

void Locator::provideArgs(char arg[]) {
    Locator::rootPath = boost::filesystem::canonical(arg).remove_filename().parent_path();
    if (!rootPath.has_filename()) std::cout << "TO-DO";
}
