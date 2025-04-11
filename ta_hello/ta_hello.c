#include <string.h>
#include "tee_internal_api.h"
#include "ta_hello_ctrl.h"

/* Se define el uuid de la TA igual que el de la CA */
//#define TA_HELLO_UUID { 0x12345678, 0x8765, 0x4321, { 'H', 'E', 'L', 'L', 'O', 'A', 'P', 'P' }}

#define HELLO_CMD 0
#define MAX_MSG_SIZE 64

// Se invoca cuando la TA es cargada.
TEE_Result TA_CreateEntryPoint(void)
{
    return TEE_SUCCESS;
}

// Se invoca cuando la TA es destruida.
void TA_DestroyEntryPoint(void)
{
    
}

// Se invoca al abrir una sesión.
TEE_Result TA_OpenSessionEntryPoint(uint32_t paramTypes,
                                    TEE_Param params[4],
                                    void **sessionContext)
{
    (void)paramTypes;
    (void)params;
    (void)sessionContext;
    return TEE_SUCCESS;
}

// Se invoca al cerrar una sesión.
void TA_CloseSessionEntryPoint(void *sessionContext)
{
    (void)sessionContext;
}


// Función central que ejecuta comandos de la CA.
TEE_Result TA_InvokeCommandEntryPoint(void *sessionContext,
    uint32_t commandID,
    uint32_t paramTypes,
    TEE_Param params[4])
{
    (void)sessionContext;

    /* Verificar que el primer parámetro sea del tipo MEMREF WHOLE */
    //if (TEE_PARAM_TYPE_GET(paramTypes, 0) != TEE_PARAM_TYPE_MEMREF_WHOLE)
    //return TEE_ERROR_BAD_PARAMETERS;

    switch (commandID) {
        case HELLO_CMD:
        {
            char *recv_msg = (char *)params[0].memref.buffer;
            // Se imprime el mensaje recibido desde la CA
            TEE_Printf("TA: Mensaje recibido: %s\n", recv_msg);
            // Se imprime el mensaje retornado como respuesta desde la TA
            TEE_Printf("TA: Respuesta enviada: %s\n", "Hola desde la TA!");
            return TEE_SUCCESS;
        }
        default:
            return TEE_ERROR_BAD_PARAMETERS;
    }
}
