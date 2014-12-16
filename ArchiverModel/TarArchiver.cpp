#include "TarArchiver.hpp"

#include "ArchiveReader/ArchiveReader.hpp"

namespace Archiver
{
TarArchiver::TarArchiver() : m_ArchiveReader(new ArchiveReader())
{
}

void TarArchiver::OpenArchive(const std::string& archiveName)
{
    m_ArchiveReader->OpenArchive(archiveName);
    m_ArchiveReader->ReadAllHeaders();
}

std::vector<Header>& TarArchiver::GetFileCollection() const
{
    return m_ArchiveReader->GetAllHeaders();
}


}
