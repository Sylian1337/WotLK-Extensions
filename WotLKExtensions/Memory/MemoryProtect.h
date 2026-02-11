#pragma once
#include <Windows.h>

class MemoryProtect
{
public:
    MemoryProtect(void* address, size_t size, DWORD newProtection)
        : m_address(address), m_size(size), m_oldProtection(0), m_valid(false)
    {
        if (VirtualProtect(m_address, m_size, newProtection, &m_oldProtection))
            m_valid = true;
    }

    ~MemoryProtect()
    {
        if (m_valid)
            VirtualProtect(m_address, m_size, m_oldProtection, &m_oldProtection);
    }

    bool IsValid() const { return m_valid; }

    inline void* PageAlign(void* addr)
    {
        SYSTEM_INFO si;
        GetSystemInfo(&si);
        return (void*)((uintptr_t)addr & ~(si.dwPageSize - 1));
    }

private:
    void*  m_address;
    size_t m_size;
    DWORD  m_oldProtection;
    bool   m_valid;
};