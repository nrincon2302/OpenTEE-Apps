#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tee_client_api.h"

/* Define el mismo UUID que en la TA */
static const TEEC_UUID TA_HELLO_UUID = {
    0x12345678, 0x8765, 0x4321,
    { 'H', 'E', 'L', 'L', 'O', 'A', 'P', 'P' }
};

/* Comando definido para enviar el mensaje */
#define HELLO_CMD 0

/* Tamaño máximo del mensaje */
#define MAX_MSG_SIZE 64

/* Función Main de la CA */
int main(void)
{
    TEEC_Result res;
    TEEC_Context ctx;
    TEEC_Session sess;
	TEEC_Operation operation;
	uint32_t conn_method = TEEC_LOGIN_PUBLIC;
    uint32_t err_origin;
    char message[MAX_MSG_SIZE] = "Hello World";

    /* Inicializar el contexto */
    res = TEEC_InitializeContext(NULL, &ctx);
    if (res != TEEC_SUCCESS) {
        printf("No se pudo inicializar el contexto (error 0x%x)\n", res);
        return -1;
    }

    /* Preparar la operación para enviar el mensaje */
	// memset(&operation, 0, sizeof(operation));
    // /* Se utiliza un parámetro de tipo MEMREF WHOLE para enviar el mensaje */
    // operation.paramTypes = TEEC_PARAM_TYPES(TEEC_MEMREF_WHOLE, TEEC_NONE,
    //                                  TEEC_NONE, TEEC_NONE);
    // operation.params[0].tmpref.buffer = message;
    // operation.params[0].tmpref.size = strlen(message) + 1;
    
    /* Abrir sesión con la TA */
    res = TEEC_OpenSession(&ctx, &sess, &TA_HELLO_UUID,
                           conn_method, NULL, &operation, &err_origin);
    if (res != TEEC_SUCCESS) {
        printf("No se pudo abrir la sesión (error 0x%x), origin 0x%x\n", res, err_origin);
        TEEC_FinalizeContext(&ctx);
        return -1;
    }
    
    /* Invocar el comando HELLO_CMD en la TA */
    res = TEEC_InvokeCommand(&sess, HELLO_CMD, &operation, NULL);
    if (res != TEEC_SUCCESS) {
        printf("Invocación del comando HELLO_CMD falló (error 0x%x)\n", res);
    } else {
        printf("Mensaje enviado con éxito a la TA: %s\n", message);
    }

    /* Cierra la sesión y finaliza el contexto */
    TEEC_CloseSession(&sess);
    TEEC_FinalizeContext(&ctx);
    
    return 0;
}