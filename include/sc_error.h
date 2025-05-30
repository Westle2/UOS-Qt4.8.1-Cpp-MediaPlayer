#ifndef SC_ERROR_API_H
#define SC_ERROR_API_H
typedef enum {
    SPARKCHAIN_ERR_SUCCESS        = 0,  // 操作成功
    SPARKCHAIN_ERR_GENERAL_FAILED = 1,  // 一般错误

    SPARKCHAIN_ERR_AUTH         = 18000,                // 授权部分
    SPARKCHAIN_ERR_RES          = SPARKCHAIN_ERR_AUTH + 100,  // 资源部分
    SPARKCHAIN_ERR_ENG          = SPARKCHAIN_ERR_AUTH + 200,  // 引擎部分
    SPARKCHAIN_ERR_SDK          = SPARKCHAIN_ERR_AUTH + 300,  // SDK部分
    SPARKCHAIN_ERR_SYS          = SPARKCHAIN_ERR_AUTH + 400,  // 系统部分
    SPARKCHAIN_ERR_PARAM        = SPARKCHAIN_ERR_AUTH + 500,  // 参数部分
    SPARKCHAIN_ERR_PROTOCOL     = SPARKCHAIN_ERR_AUTH + 600,  // 协议部分
    SPARKCHAIN_ERR_CLOUD        = SPARKCHAIN_ERR_AUTH + 700,  // 云端错误
    SPARKCHAIN_ERR_LOCAL_NET    = SPARKCHAIN_ERR_AUTH + 800,  //本地网络网络
    SPARKCHAIN_ERR_SPARK        = SPARKCHAIN_ERR_AUTH + 900,  // spark大模型错误
    SPARKCHAIN_ERR_DEVICE_AUTH  = SPARKCHAIN_ERR_AUTH + 1000,  // spark大模型错误

    SPARKCHAIN_ERR_AUTH_LICENSE_NOT_FOUND    = SPARKCHAIN_ERR_AUTH + 0,  // 18000 本地license文件不存在
    SPARKCHAIN_ERR_AUTH_LICENSE_FILE_INVALID = SPARKCHAIN_ERR_AUTH + 1,  // 18001 授权文件内容非法
    SPARKCHAIN_ERR_AUTH_LICENSE_PARSE_FAILED = SPARKCHAIN_ERR_AUTH + 2,  // 18002 授权文件解析失败
    SPARKCHAIN_ERR_AUTH_PAYLOAD_DEFECT       = SPARKCHAIN_ERR_AUTH + 3,  // 18003 payload内容缺失
    SPARKCHAIN_ERR_AUTH_SIGN_DEFECT          = SPARKCHAIN_ERR_AUTH + 4,  // 18004 signature内容缺失
    SPARKCHAIN_ERR_AUTH_EXPIRED              = SPARKCHAIN_ERR_AUTH + 5,  // 18005 授权已过期
    SPARKCHAIN_ERR_AUTH_TIME_ERROR           = SPARKCHAIN_ERR_AUTH + 6,  // 18006 授权时间错误，比正常时间慢30分钟以上
    SPARKCHAIN_ERR_AUTH_APP_NOT_MATCH        = SPARKCHAIN_ERR_AUTH + 7,  // 18007 授权应用不匹配（apiKey、apiSecret）
    SPARKCHAIN_ERR_AUTH_LICENSE_EXPIRED      = SPARKCHAIN_ERR_AUTH + 8,  // 18008 授权文件激活过期
    SPARKCHAIN_ERR_AUTH_NULL_APP_PTR         = SPARKCHAIN_ERR_AUTH + 9,  // 18009 授权app信息指针为空
    SPARKCHAIN_ERR_AUTH_PLATFORM_NOT_MATCH   = SPARKCHAIN_ERR_AUTH + 10, // 18010 离线授权激活文件指定平台与设备平台不匹配
    SPARKCHAIN_ERR_AUTH_ARCH_NOT_MATCH       = SPARKCHAIN_ERR_AUTH + 11, // 18011 离线授权激活文件指定架构与设备cpu架构不匹配
    SPARKCHAIN_ERR_AUTH_WRONG_LICENSE_NUM    = SPARKCHAIN_ERR_AUTH + 12, // 18012 离线授权激活文件中包含License个数异常
    SPARKCHAIN_ERR_AUTH_DEVICE_NOT_FOUND     = SPARKCHAIN_ERR_AUTH + 13, // 18013 离线授权激活文件中未找到当前设备
    SPARKCHAIN_ERR_AUTH_LEVEL_NOT_VALID      = SPARKCHAIN_ERR_AUTH + 14, // 18014 离线授权激活文件中设备指纹安全等级非法
    SPARKCHAIN_ERR_AUTH_HARDWARE_FAILED      = SPARKCHAIN_ERR_AUTH + 15, // 18015 硬件授权验证失败
    SPARKCHAIN_ERR_AUTH_OFFLINE_PROT_INVALID = SPARKCHAIN_ERR_AUTH + 16, // 18016 离线授权激活文件内容非法
    SPARKCHAIN_ERR_AUTH_HEADER_INVALID       = SPARKCHAIN_ERR_AUTH + 17, // 18017 离线授权激活文件中协议头非法
    SPARKCHAIN_ERR_AUTH_PART_COUNT_INVALID   = SPARKCHAIN_ERR_AUTH + 18, // 18018 离线授权激活文件中指纹组成项个数为0
    SPARKCHAIN_ERR_AUTH_RESOURCE_EXPIREd     = SPARKCHAIN_ERR_AUTH + 19, // 18019 资源已过期

    SPARKCHAIN_ERR_RES_VERIFY_FAILED = SPARKCHAIN_ERR_RES + 0,  // 18100 资源鉴权失败
    SPARKCHAIN_ERR_RES_INVALID_HEADER= SPARKCHAIN_ERR_RES + 1,  // 18101 资源格式解析失败
    SPARKCHAIN_ERR_RES_NOT_MATCH     = SPARKCHAIN_ERR_RES + 2,  // 18102 资源(与引擎)不匹配
    SPARKCHAIN_ERR_RES_NULL_PTR      = SPARKCHAIN_ERR_RES + 3,  // 18103 资源参数不存在（指针为NULL）
    SPARKCHAIN_ERR_RES_OPEN_FAILED   = SPARKCHAIN_ERR_RES + 4,  // 18104 资源路径打开失败
    SPARKCHAIN_ERR_RES_LOAD_FAILED   = SPARKCHAIN_ERR_RES + 5,  // 18105 资源加载失败，workDir内未找到对应资源
    SPARKCHAIN_ERR_RES_UNLOAD_FAILED = SPARKCHAIN_ERR_RES + 6,  // 18106 资源卸载失败, 卸载的资源未加载过

    SPARKCHAIN_ERR_ENG_VERIFY_FAILED   = SPARKCHAIN_ERR_ENG + 0,  // 18200 引擎鉴权失败
    SPARKCHAIN_ERR_ENG_LOAD_FAILED     = SPARKCHAIN_ERR_ENG + 1,  // 18201 引擎动态加载失败
    SPARKCHAIN_ERR_ENG_NOT_INITED      = SPARKCHAIN_ERR_ENG + 2,  // 18202 引擎未初始化
    SPARKCHAIN_ERR_ENG_API_NOT_SUPPORT = SPARKCHAIN_ERR_ENG + 3,  // 18203 引擎不支持该接口调用
    SPARKCHAIN_ERR_ENG_NULL_CREATE_PTR = SPARKCHAIN_ERR_ENG + 4,  // 18204 引擎craete函数指针为空

    SPARKCHAIN_ERR_SDK_INVALID                  = SPARKCHAIN_ERR_SDK + 0,   // 18300 sdk不可用
    SPARKCHAIN_ERR_SDK_NOT_INITED               = SPARKCHAIN_ERR_SDK + 1,   // 18301 sdk没有初始化
    SPARKCHAIN_ERR_SDK_INIT_FAILED              = SPARKCHAIN_ERR_SDK + 2,   // 18302 sdk初始化失败
    SPARKCHAIN_ERR_SDK_ALREADY_INIT             = SPARKCHAIN_ERR_SDK + 3,   // 18303 sdk已经初始化
    SPARKCHAIN_ERR_SDK_INVALID_PARAM            = SPARKCHAIN_ERR_SDK + 4,   // 18304 sdk不合法参数
    SPARKCHAIN_ERR_SDK_NULL_SESSION_HANDLE      = SPARKCHAIN_ERR_SDK + 5,   // 18305 sdk会话handle为空
    SPARKCHAIN_ERR_SDK_SESSION_NOT_FOUND        = SPARKCHAIN_ERR_SDK + 6,   // 18306 sdk会话未找到
    SPARKCHAIN_ERR_SDK_SESSION_ALREADY_END      = SPARKCHAIN_ERR_SDK + 7,   // 18307 sdk会话重复终止
    SPARKCHAIN_ERR_SDK_TIMEOUT                  = SPARKCHAIN_ERR_SDK + 8,   // 18308 超时错误
    SPARKCHAIN_ERR_SDK_INITING                  = SPARKCHAIN_ERR_SDK + 9,   // 18309 sdk正在初始化中
    SPARKCHAIN_ERR_SDK_SESSEION_ALREAY_START    = SPARKCHAIN_ERR_SDK + 10,  // 18310 sdk会话重复开启
    SPARKCHAIN_ERR_SDK_CONCURRENT_OVERFLOW      = SPARKCHAIN_ERR_SDK + 11,  // 18311 sdk同一能力并发路数超出最大限制
    SPARKCHAIN_ERR_IS_RUNNING                   = SPARKCHAIN_ERR_SDK + 12,  // 18312 此实例已处在运行态，禁止单实例并发运行

    SPARKCHAIN_ERR_SYS_WORK_DIR_ILLEGAL         = SPARKCHAIN_ERR_SYS + 0,  // 18400 工作目录无写权限
    SPARKCHAIN_ERR_SYS_DEVICE_UNKNOWN           = SPARKCHAIN_ERR_SYS + 1,  // 18401 设备指纹获取失败，设备未知
    SPARKCHAIN_ERR_SYS_FILE_OPEN_FAILED         = SPARKCHAIN_ERR_SYS + 2,  // 18402 文件打开失败
    SPARKCHAIN_ERR_SYS_MEM_ALLOC_FAILED         = SPARKCHAIN_ERR_SYS + 3,  // 18403 内存分配失败
    SPARKCHAIN_ERR_SYS_DEVICE_COMPARE_FAILED    = SPARKCHAIN_ERR_SYS + 4,  // 18404 设备指纹比较失败

    SPARKCHAIN_ERR_PARAM_NOT_FOUND                = SPARKCHAIN_ERR_PARAM + 0,   // 18500 未找到该参数key
    SPARKCHAIN_ERR_PARAM_OVERFLOW                 = SPARKCHAIN_ERR_PARAM + 1,   // 18501 参数范围溢出，不满足约束条件
    SPARKCHAIN_ERR_PARAM_NULL_INIT_PARAM_PTR      = SPARKCHAIN_ERR_PARAM + 2,   // 18502 sdk初始化参数为空
    SPARKCHAIN_ERR_PARAM_NULL_APPID_PTR           = SPARKCHAIN_ERR_PARAM + 3,   // 18503 sdk初始化参数中appid为空
    SPARKCHAIN_ERR_PARAM_NULL_APIKEY_PTR          = SPARKCHAIN_ERR_PARAM + 4,   // 18504 sdk初始化参数中apiKey为空
    SPARKCHAIN_ERR_PARAM_NULL_APISECRET_PTR       = SPARKCHAIN_ERR_PARAM + 5,   // 18505 sdk初始化参数中apiSecret为空
    SPARKCHAIN_ERR_PARAM_NULL_ABILITY_PTR         = SPARKCHAIN_ERR_PARAM + 6,   // 18506 ability参数为空
    SPARKCHAIN_ERR_PARAM_NULL_INPUT_PTR           = SPARKCHAIN_ERR_PARAM + 7,   // 18507 input参数为空
    SPARKCHAIN_ERR_PARAM_DATA_KEY_NOT_EXIST       = SPARKCHAIN_ERR_PARAM + 8,   // 18508 输入数据参数Key不存在
    SPARKCHAIN_ERR_PARAM_REQUIRED_MISSED          = SPARKCHAIN_ERR_PARAM + 9,   // 18509 必填参数缺失
    SPARKCHAIN_ERR_PARAM_NULL_OUTPUT_PTR          = SPARKCHAIN_ERR_PARAM + 10,  // 18510 output参数缺失
    SPARKCHAIN_ERR_CODEC_NOT_SUPPORT              = SPARKCHAIN_ERR_PARAM + 20,  // 18520 不支持的编解码类型
    SPARKCHAIN_ERR_CODEC_NULL_PTR                 = SPARKCHAIN_ERR_PARAM + 21,  // 18521 编解码handle指针为空
    SPARKCHAIN_ERR_CODEC_MODULE_MISSED            = SPARKCHAIN_ERR_PARAM + 22,  // 18522 编解码模块条件编译未打开
    SPARKCHAIN_ERR_CODEC_ENCODE_FAIL              = SPARKCHAIN_ERR_PARAM + 23,  // 18523 编码错误
    SPARKCHAIN_ERR_CODEC_DECODE_FAIL              = SPARKCHAIN_ERR_PARAM + 24,  // 18524 解码错误

    SPARKCHAIN_ERR_VAD_RESPONSE_TIMEOUT           = SPARKCHAIN_ERR_PARAM + 30,  // VAD静音超时

    SPARKCHAIN_ERR_PROTOCOL_TIMESTAMP_MISSING        = SPARKCHAIN_ERR_PROTOCOL + 0, // 18600 协议中时间戳字段缺失
    SPARKCHAIN_ERR_PROTOCOL_ABILITY_NOT_FOUND        = SPARKCHAIN_ERR_PROTOCOL + 1, // 18601 协议中未找到该能力ID
    SPARKCHAIN_ERR_PROTOCOL_RESOURCE_NOT_FOUND       = SPARKCHAIN_ERR_PROTOCOL + 2, // 18602 协议中未找到该资源ID
    SPARKCHAIN_ERR_PROTOCOL_ENGINE_NOT_FOUND         = SPARKCHAIN_ERR_PROTOCOL + 3, // 18603 协议中未找到该引擎ID
    SPARKCHAIN_ERR_PROTOCOL_ZERO_ENGINE_NUM          = SPARKCHAIN_ERR_PROTOCOL + 4, // 18604 协议中引擎个数为0
    SPARKCHAIN_ERR_PROTOCOL_NOT_LOADED               = SPARKCHAIN_ERR_PROTOCOL + 5, // 18605 协议未被初始化解析
    SPARKCHAIN_ERR_PROTOCOL_INTERFACE_TYPE_NOT_MATCH = SPARKCHAIN_ERR_PROTOCOL + 6, // 18606 协议能力接口类型不匹配
    SPARKCHAIN_ERR_PROTOCOL_TEMP_VERIFY_FAILED       = SPARKCHAIN_ERR_PROTOCOL + 7, // 18607 预置协议解析失败

    SPARKCHAIN_ERR_CLOUD_GENERAL_FAILED          = SPARKCHAIN_ERR_CLOUD + 0,  // 18700 通用网络错误
    SPARKCHAIN_ERR_CLOUD_CONNECT_FAILED          = SPARKCHAIN_ERR_CLOUD + 1,  // 18701 网路不通
    SPARKCHAIN_ERR_CLOUD_403                     = SPARKCHAIN_ERR_CLOUD + 2,  // 18702 网关检查不过
    SPARKCHAIN_ERR_CLOUD_WRONG_RSP_FORMAT        = SPARKCHAIN_ERR_CLOUD + 3,  // 18703 云端响应格式不对
    SPARKCHAIN_ERR_CLOUD_APP_NOT_FOUND           = SPARKCHAIN_ERR_CLOUD + 4,  // 18704 应用未注册
    SPARKCHAIN_ERR_CLOUD_APP_CHECK_FAILED        = SPARKCHAIN_ERR_CLOUD + 5,  // 18705 应用apiKey&&apiSecret校验失败
    SPARKCHAIN_ERR_CLOUD_WRONG_ARCHITECT         = SPARKCHAIN_ERR_CLOUD + 6,  // 18706 引擎不支持的平台架构
    SPARKCHAIN_ERR_CLOUD_AUTH_EXPIRED            = SPARKCHAIN_ERR_CLOUD + 7,  // 18707 授权已过期
    SPARKCHAIN_ERR_CLOUD_AUTH_FULL               = SPARKCHAIN_ERR_CLOUD + 8,  // 18708 授权数量已满
    SPARKCHAIN_ERR_CLOUD_ABILITY_NOT_FOUND       = SPARKCHAIN_ERR_CLOUD + 9,  // 18709 未找到该app绑定的能力
    SPARKCHAIN_ERR_CLOUD_RESOURCE_NOT_FOUND      = SPARKCHAIN_ERR_CLOUD + 10, // 18710 未找到该app绑定的能力资源
    SPARKCHAIN_ERR_CLOUD_JSON_PARSE_FAILED       = SPARKCHAIN_ERR_CLOUD + 11, // 18711 JSON操作失败
    SPARKCHAIN_ERR_CLOUD_404                     = SPARKCHAIN_ERR_CLOUD + 12, // 18712 http 404错误
    SPARKCHAIN_ERR_CLOUD_LEVEL_NOT_MATCH         = SPARKCHAIN_ERR_CLOUD + 13, // 18713 设备指纹安全等级不匹配
    SPARKCHAIN_ERR_CLOUD_401                     = SPARKCHAIN_ERR_CLOUD + 14, // 18714 用户没有访问权限，需要进行身份认证
    SPARKCHAIN_ERR_CLOUD_SDK_NOT_FOUND           = SPARKCHAIN_ERR_CLOUD + 15, // 18715 未找到该SDK ID
    SPARKCHAIN_ERR_CLOUD_ABILITYS_NOT_FOUND      = SPARKCHAIN_ERR_CLOUD + 16, // 18716 未找到该组合能力集合
    SPARKCHAIN_ERR_CLOUD_ABILITY_NOT_ENOUGH      = SPARKCHAIN_ERR_CLOUD + 17, // 18717 SDK组合能力授权不足
    SPARKCHAIN_ERR_CLOUD_APP_SIG_INVALID         = SPARKCHAIN_ERR_CLOUD + 18, // 18718 无效授权应用签名
    SPARKCHAIN_ERR_CLOUD_APP_SIG_NOT_UNIQUE      = SPARKCHAIN_ERR_CLOUD + 19, // 18719 应用签名不唯一
    SPARKCHAIN_ERR_CLOUD_SCHEMA_INVALID          = SPARKCHAIN_ERR_CLOUD + 20, // 18720 能力schema不可用
    SPARKCHAIN_ERR_CLOUD_TEMPLATE_NOT_FOUND      = SPARKCHAIN_ERR_CLOUD + 21, // 18721 竞争授权: 未找到能力集模板
    SPARKCHAIN_ERR_CLOUD_ABILITY_NOT_IN_TEMPLATE = SPARKCHAIN_ERR_CLOUD + 22, // 18722 竞争授权: 能力不在模板能力集模板中

    SPARKCHAIN_ERR_LOCAL_NET_CONNECT_FAILED      = SPARKCHAIN_ERR_LOCAL_NET + 1, // 18801 连接建立出错
    SPARKCHAIN_ERR_LOCAL_NET_RES_WAIT_TIMEOUT    = SPARKCHAIN_ERR_LOCAL_NET + 2, // 18802 结果等待超时
    SPARKCHAIN_ERR_LOCAL_NET_CONNECT_ERROR       = SPARKCHAIN_ERR_LOCAL_NET + 3, // 18803 连接状态异常

    SPARKCHAIN_ERR_CONCURRENT_OVERFLOW           = SPARKCHAIN_ERR_SPARK + 2,  // 18902 并发超过路数限制
    SPARKCHAIN_ERR_AGENT_NEXT_STEPS_EMPTY        = SPARKCHAIN_ERR_SPARK + 3,  // 18903 大模型规划步骤为空
    SPARKCHAIN_ERR_AGENT_PLUGIN_NOT_FOUND        = SPARKCHAIN_ERR_SPARK + 4,  // 18904 插件为找到
    SPARKCHAIN_ERR_AGENT_ITERATION_EXCEEDS       = SPARKCHAIN_ERR_SPARK + 6,  // 18906 与大模型交互次数超限制
    SPARKCHAIN_ERR_AGENT_TIMETAKEN_EXCEEDS       = SPARKCHAIN_ERR_SPARK + 7,  // 18907 运行超限制时长
    SPARKCHAIN_ERR_AGENT_ANSWER_FORMAT_ERR       = SPARKCHAIN_ERR_SPARK + 8,  // 18908 大模型返回结果格式异常
    SPARKCHAIN_ERR_SPARK_TEXT_INVALID            = SPARKCHAIN_ERR_SPARK + 52, // 18952 输入数据为空或异常

    SPARKCHAIN_ERR_DEVICE_AUTH_DISABLED                    = SPARKCHAIN_ERR_DEVICE_AUTH + 1,     // 19001: 设备级授权: 设备被禁用
    SPARKCHAIN_ERR_DEVICE_AUTH_PARSE_FAILED                = SPARKCHAIN_ERR_DEVICE_AUTH + 2,     // 19002: 设备级授权: 协议解析失败
    SPARKCHAIN_ERR_DEVICE_AUTH_LICENSE_INVALID             = SPARKCHAIN_ERR_DEVICE_AUTH + 3,     // 19003: 设备级授权: 本地缓存获取失败
    SPARKCHAIN_ERR_DEVICE_AUTH_NO_NETWORK                  = SPARKCHAIN_ERR_DEVICE_AUTH + 4,     // 19004: 设备级授权: 无网络
    SPARKCHAIN_ERR_DEVICE_AUTH_NOT_FOUND                   = SPARKCHAIN_ERR_DEVICE_AUTH + 5,     // 19005: 设备级授权: 授权未找到
    SPARKCHAIN_ERR_DEVICE_AUTH_GET_FAILURE                 = SPARKCHAIN_ERR_DEVICE_AUTH + 6,     // 19006: 设备级授权: 设备授权获取失败
    SPARKCHAIN_ERR_DEVICE_AUTH_BLACKLIST_DISABLED          = SPARKCHAIN_ERR_DEVICE_AUTH + 7,     // 19007: 设备级授权: 当前设备处于黑名单
    SPARKCHAIN_ERR_DEVICE_AUTH_WHITELIST_DISABLED          = SPARKCHAIN_ERR_DEVICE_AUTH + 8,     // 19008: 设备级授权: 当前设备不在白名单
    SPARKCHAIN_ERR_DEVICE_AUTH_CLOUD_INVALID_PARAMETER     = SPARKCHAIN_ERR_DEVICE_AUTH + 9,     // 19010: 设备级授权: 鉴权参数非法
    SPARKCHAIN_ERR_DEVICE_AUTH_WRONG_APPID                 = SPARKCHAIN_ERR_DEVICE_AUTH + 10,    // 20011: 设备级授权: 不匹配的appid
} SPARKCHAIN_ERR;

#endif