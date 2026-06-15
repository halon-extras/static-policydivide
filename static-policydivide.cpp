#include <HalonMTA.h>
#include <stdlib.h>

HALON_EXPORT
int Halon_version()
{
	return HALONMTA_PLUGIN_VERSION;
}

HALON_EXPORT
bool Halon_init(HalonInitContext* hic)
{
	HalonConfig* cfg;
	HalonMTA_init_getinfo(hic, HALONMTA_INIT_APPCONFIG, nullptr, 0, &cfg, nullptr);

	const char* _hosts = HalonMTA_config_string_get(HalonMTA_config_object_get(cfg, "hosts"), nullptr);
	if (_hosts)
	{
		unsigned long hosts = strtoul(_hosts, nullptr, 10);
		HalonMTA_queue_policy_divide(hosts);
	}

	return true;
}

HALON_EXPORT
void Halon_config_reload(HalonConfig* hc)
{
	const char* _hosts = HalonMTA_config_string_get(HalonMTA_config_object_get(hc, "hosts"), nullptr);
	if (_hosts)
	{
		unsigned long hosts = strtoul(_hosts, nullptr, 10);
		HalonMTA_queue_policy_divide(hosts);
	}
}
