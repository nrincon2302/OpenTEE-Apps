#include <tee_internal_api.h>
#include <trace.h> 

/* Se define el uuid de la TA igual que el de la CA */
#define TA_HELLO_UUID { 0xe7b8c9d0, 0x1234, 0x5678, \
    { 0x9a, 0xbc, 0xde, 0xf0, 0x12, 0x34, 0x56, 0x78 } }

/* Funciones de una TA */
TEE_Result TA_CreateEntryPoint(void)
{
    IMSG("TA Hello: Entry Point Created");
    return TEE_SUCCESS;
}

void TA_DestroyEntryPoint(void)
{
    IMSG("TA Hello: Entry Point Destroyed");
}

TEE_Result TA_OpenSessionEntryPoint(uint32_t param_types,
        TEE_Param params[4], void **session_context)
{
    IMSG("TA Hello: Session Opened");
    return TEE_SUCCESS;
}

void TA_CloseSessionEntryPoint(void *session_context)
{
    IMSG("TA Hello: Session Closed");
}

TEE_Result TA_InvokeCommandEntryPoint(void *session_context,
        uint32_t command_id, uint32_t param_types,
        TEE_Param params[4])
{
    /* Mostramos un mensaje de recepción y correspondencia */
    IMSG("TA Hello: Hola Mundo desde la TA");
    return TEE_SUCCESS;
}
