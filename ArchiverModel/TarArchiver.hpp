#ifndef TARARCHHIVER_HPP
#define TARARCHHIVER_HPP

#include "Header/Header.hpp"

#include <string>
#include <memory>

namespace Archiver
{

class ArchiveReader;

class TarArchiver
{
public:
    TarArchiver();

    void OpenArchive(const std::string& archiveName);

    std::vector<Header>& GetFileCollection() const;

private:

    std::shared_ptr<ArchiveReader> m_ArchiveReader;

};
}

#endif // TARARCHHIVER_HPP
