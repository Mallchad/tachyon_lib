
#pragma once

namespace tyon
{

typedef BOOL (WINAPI *proc_LogicalProcessorInformationEx)(
    LOGICAL_PROCESSOR_RELATIONSHIP, PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX, PDWORD
);

}
