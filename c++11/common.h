#ifndef CXX11_EXAMPLES_COMMON_H
#define CXX11_EXAMPLES_COMMON_H

class LifecycleLogger
{
private:
    std::ostream &m_logStream;
public:
    LifecycleLogger(std::ostream &s=std::cout): m_logStream(s)
    {
        m_logStream << "[LifecycleLogger] Instance created at 0x"
            << std::hex << this << std::dec << std::endl;
    }

    virtual ~LifecycleLogger() {
        m_logStream << "[LifecycleLogger] Instance deconstructed at 0x"
            << std::hex << this << std::dec << std::endl;
    }
};

#endif
