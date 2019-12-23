#include "GenericResource.h"
#include <string.h>
#include <stdlib.h>

static SizeT size_of_file(StringView path);

#ifndef __unix__
#error currently not supported, since we need <sys/stat> (TODO)
#else
#include <sys/stat.h>
static SizeT size_of_file(StringView path)
{
    struct stat sb;
    int         stat_rc = stat(path.c_str(), &sb);
    ASSERT(stat_rc == 0);
    return static_cast<SizeT>(sb.st_size);
}
#endif

GenericResource::GenericResource() : m_path("")
{
    verbose("WARNING: empty path in " << __PRETTY_FUNCTION__);
}

GenericResource::GenericResource(const Path& path) : m_path(path)
{
}

GenericResource::~GenericResource()
{
    if (m_data.is_null())
        LOG("GenericResource of path " << m_path << " was never loaded (nullptr)");

    if (m_is_loaded)
        free(m_data);
}

void GenericResource::load_async()
{
    NOTIMPL
}

void GenericResource::load()
{
    ASSERT(m_is_loaded == false);
    // needs to be null, otherwise already loaded!
    ASSERT(m_data.is_null());
    FILE* fp = fopen(m_path.c_str(), "rb");
    ASSERT(fp != nullptr);
    m_size = size_of_file(m_path.c_str());
    // FIXME: Possibly add a nullterminator at the end?
    m_data = malloc(m_size + 1 * sizeof(char));
    ASSERT(m_data.is_not_null());
    int fread_rc = fread(m_data, 1, m_size, fp);
    ASSERT(fread_rc == m_size);
    fclose(fp);
    // FIXME: null term here if needed (view FIXME above)
    // TEMPORARY!
    m_data.as_ptr<char>()[m_size] = 0;

    m_is_loaded = true;
}

void GenericResource::unload()
{
    ASSERT(m_is_loaded == true);
    free(m_data);
    m_size      = 0;
    m_is_loaded = false;
}

void GenericResource::reload()
{
    ASSERT(m_is_loaded == true);
    unload();
    load();
}

RawPtr<void> GenericResource::data_as_void_ptr()
{
    return m_data;
}

const RawPtr<void> GenericResource::data_as_void_ptr() const
{
    return m_data;
}

SizeT GenericResource::size() const
{
    return m_size;
}
