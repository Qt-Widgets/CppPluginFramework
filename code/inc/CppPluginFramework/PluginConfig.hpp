/* This file is part of C++ Plugin Framework.
 *
 * C++ Plugin Framework is free software: you can redistribute it and/or modify it under the terms
 * of the GNU Lesser General Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * C++ Plugin Framework is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along with C++ Plugin
 * Framework. If not, see <http://www.gnu.org/licenses/>.
 */

/*!
 * \file
 *
 * Contains a class that holds a plugin's config
 */

#ifndef CPPPLUGINFRAMEWORK_PLUGINCONFIG_HPP
#define CPPPLUGINFRAMEWORK_PLUGINCONFIG_HPP

// C++ Plugin Framework includes
#include <CppPluginFramework/PluginInstanceConfig.hpp>
#include <CppPluginFramework/VersionInfo.hpp>

// Qt includes
#include <QtCore/QList>

// System includes

// Forward declarations

// Macros

namespace CppPluginFramework
{

/*!
 * This class holds a plugin's config
 */
class CPPPLUGINFRAMEWORK_LIBRARY_EXPORT PluginConfig
{
public:
    /*!
     * Constructor
     */
    PluginConfig() = default;

    /*!
     * Constructor
     *
     * \param   filePath        Path to the plugin's library
     * \param   version         Required plugin version
     * \param   instanceConfigs List of plugin's instance configs
     */
    PluginConfig(const QString &filePath,
                 const VersionInfo &version,
                 const QList<PluginInstanceConfig> &instanceConfigs = QList<PluginInstanceConfig>());

    /*!
     * Constructor
     *
     * \param   filePath        Path to the plugin's library
     * \param   minVersion      Minimum required plugin version
     * \param   maxVersion      Maximum required plugin version
     * \param   instanceConfigs List of plugin's instance configs
     */
    PluginConfig(const QString &filePath,
                 const VersionInfo &minVersion,
                 const VersionInfo &maxVersion,
                 const QList<PluginInstanceConfig> &instanceConfigs = QList<PluginInstanceConfig>());

    /*!
     * Checks if plugin config is valid
     *
     * \retval  true    Plugin config is valid
     * \retval  false   Plugin config is not valid
     */
    bool isValid() const;

    /*!
     * Checks if a specific version is required
     *
     * \retval  true    A specific version is required
     * \retval  false   A version range is allowed
     */
    bool isExactVersion() const;

    /*!
     * Checks if a version range is allowed
     *
     * \retval  true    A version range is allowed
     * \retval  false   A specific version is required
     */
    bool isVersionRange() const;

    /*!
     * Returns file path to the plugin's library
     *
     * \return  File path to the plugin's library
     */
    QString filePath() const;

    /*!
     * Sets file path to the plugin's library
     *
     * \param   filePath    File path to the plugin's library
     */
    void setFilePath(const QString &filePath);

    /*!
     * Returns plugin's required version
     *
     * \return  Plugin's required version
     */
    VersionInfo version() const;

    /*!
     * Sets plugin's required version
     *
     * \param   version     Plugin's required version
     */
    void setVersion(const VersionInfo &version);

    /*!
     * Returns plugin's required minimum version
     *
     * \return  Plugin's required minimum version
     */
    VersionInfo minVersion() const;

    /*!
     * Sets plugin's required minimum version
     *
     * \param   minVersion  Plugin's required minimum version
     */
    void setMinVersion(const VersionInfo &minVersion);

    /*!
     * Returns plugin's required maximum version
     *
     * \return  Plugin's required maximum version
     */
    VersionInfo maxVersion() const;

    /*!
     * Sets plugin's required maximum version
     *
     * \param   minVersion  Plugin's required maximum version
     */
    void setMaxVersion(const VersionInfo &maxVersion);

    /*!
     * Returns list of plugin's instance configs
     *
     * \return  List of plugin's instance configs
     */
    QList<PluginInstanceConfig> instanceConfigs() const;

    /*!
     * Sets list of plugin's instance configs
     *
     * \param   instanceConfigs     List of plugin's instance configs
     */
    void setInstanceConfigs(const QList<PluginInstanceConfig> &instanceConfigs);

private:
    /*!
     * Holds the path to the plugin's library
     */
    QString m_filePath;

    /*!
     * Holds the plugin's required version
     */
    VersionInfo m_version;

    /*!
     * Holds the plugin's minimum required version
     */
    VersionInfo m_minVersion;

    /*!
     * Holds the plugin's maximum required version
     */
    VersionInfo m_maxVersion;

    /*!
     * Holds the list of plugin's instance configs
     */
    QList<PluginInstanceConfig> m_instanceConfigs;
};

/*!
 * Checks if the two specified plugin configs are equal
 *
 * \param   left    Plugin config
 * \param   right   Plugin config
 *
 * \retval  true    Plugin configs are equal
 * \retval  false   Plugin configs are not equal
 *
 * \note    Result of the comparison is valid only if both plugin configs are valid!
 */
bool operator==(const PluginConfig &left, const PluginConfig &right);

}

#endif // CPPPLUGINFRAMEWORK_PLUGINCONFIG_HPP
