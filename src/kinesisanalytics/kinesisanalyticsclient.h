/*
    Copyright 2013-2016 Paul Colby

    This file is part of libqtaws.

    Libqtaws is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Libqtaws is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with libqtaws.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef QTAWS_KINESISANALYTICSCLIENT_H
#define QTAWS_KINESISANALYTICSCLIENT_H

#include <QObject>

class QNetworkReply;

QTAWS_BEGIN_NAMESPACE

class AwsAbstractClient;
class AwsAbstractCredentials;
class KinesisAnalyticsClientPrivate;

class QTAWS_EXPORT KinesisAnalyticsClient : public AwsAbstractClient {
    Q_OBJECT

public:
    KinesisAnalyticsClient(
        const AwsRegion::Region region = AwsRegion::InvalidRegion,
        AwsAbstractCredentials * credentials = NULL,
        QNetworkAccessManager * const manager = NULL,
        QObject * const parent = 0);

    KinesisAnalyticsClient(
        const QUrl &endpoint, AwsAbstractCredentials * credentials = NULL,
        QNetworkAccessManager * const manager = NULL,
        QObject * const parent = 0);

public slots:
    KinesisAnalyticsAddApplicationInputResponse * addApplicationInput(const KinesisAnalyticsAddApplicationInputRequest &request);
    KinesisAnalyticsAddApplicationOutputResponse * addApplicationOutput(const KinesisAnalyticsAddApplicationOutputRequest &request);
    KinesisAnalyticsAddApplicationReferenceDataSourceResponse * addApplicationReferenceDataSource(const KinesisAnalyticsAddApplicationReferenceDataSourceRequest &request);
    KinesisAnalyticsCreateApplicationResponse * createApplication(const KinesisAnalyticsCreateApplicationRequest &request);
    KinesisAnalyticsDeleteApplicationResponse * deleteApplication(const KinesisAnalyticsDeleteApplicationRequest &request);
    KinesisAnalyticsDeleteApplicationOutputResponse * deleteApplicationOutput(const KinesisAnalyticsDeleteApplicationOutputRequest &request);
    KinesisAnalyticsDeleteApplicationReferenceDataSourceResponse * deleteApplicationReferenceDataSource(const KinesisAnalyticsDeleteApplicationReferenceDataSourceRequest &request);
    KinesisAnalyticsDescribeApplicationResponse * describeApplication(const KinesisAnalyticsDescribeApplicationRequest &request);
    KinesisAnalyticsDiscoverInputSchemaResponse * discoverInputSchema(const KinesisAnalyticsDiscoverInputSchemaRequest &request);
    KinesisAnalyticsListApplicationsResponse * listApplications(const KinesisAnalyticsListApplicationsRequest &request);
    KinesisAnalyticsStartApplicationResponse * startApplication(const KinesisAnalyticsStartApplicationRequest &request);
    KinesisAnalyticsStopApplicationResponse * stopApplication(const KinesisAnalyticsStopApplicationRequest &request);
    KinesisAnalyticsUpdateApplicationResponse * updateApplication(const KinesisAnalyticsUpdateApplicationRequest &request);

private:
    Q_DECLARE_PRIVATE(KinesisAnalyticsClient)
    Q_DISABLE_COPY(KinesisAnalyticsClient)

};

QTAWS_END_NAMESPACE

#endif
