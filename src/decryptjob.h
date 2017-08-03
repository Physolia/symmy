/*
 * Copyright (C) 2017 Elvis Angelaccio <elvis.angelaccio@kde.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#pragma once

#include "job.h"

#include <gpgme++/error.h>
#include <gpgme++/decryptionresult.h>

class QFile;
class QTemporaryFile;

namespace Symmy
{

class DecryptJob : public Job
{
    Q_OBJECT

public:
    explicit DecryptJob(const QString &ciphertextFilename);
    ~DecryptJob() override;

    QString ciphertextFilename() const override;
    QString plaintextFilename() const override;

private slots:
    void doWork() override;
    void slotResult(const GpgME::DecryptionResult &, const QByteArray &, const QString & = {}, const GpgME::Error & = {});

private:
    std::shared_ptr<QFile> m_ciphertext;
    std::shared_ptr<QTemporaryFile> m_plaintext;
};

}
