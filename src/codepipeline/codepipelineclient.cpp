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

#include "codepipelineclient.h"
#include "codepipelineclient_p.h"

#include "core/awssignaturev4.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>

QTAWS_BEGIN_NAMESPACE

/**
 * @class  CodePipelineClient
 *
 * @brief  Client for AWS CodePipeline
 *
 * <fullname>AWS CodePipeline</fullname>
 *
 +  <b>Overview</b>
 *
 + This is the AWS CodePipeline API Reference. This guide provides descriptions of the actions and data types for AWS CodePipeline. Some functionality for your pipeline is only configurable through the API. For additional information, see the <a href="http://docs.aws.amazon.com/codepipeline/latest/userguide/welcome.html">AWS CodePipeline User Guide</a>.
 *
 + You can use the AWS CodePipeline API to work with pipelines, stages, actions, gates, and transitions, as described below.
 *
 +  <i>Pipelines</i> are models of automated release processes. Each pipeline is uniquely named, and consists of actions, gates, and stages.
 *
 + You can work with pipelines by calling:
 *
 +  <ul> <li>
 *
 +  <a>CreatePipeline</a>, which creates a uniquely-named pipeline.
 *
 +  </li> <li>
 *
 +  <a>DeletePipeline</a>, which deletes the specified pipeline.
 *
 +  </li> <li>
 *
 +  <a>GetPipeline</a>, which returns information about a pipeline structure.
 *
 +  </li> <li>
 *
 +  <a>GetPipelineExecution</a>, which returns information about a specific execution of a pipeline.
 *
 +  </li> <li>
 *
 +  <a>GetPipelineState</a>, which returns information about the current state of the stages and actions of a pipeline.
 *
 +  </li> <li>
 *
 +  <a>ListPipelines</a>, which gets a summary of all of the pipelines associated with your account.
 *
 +  </li> <li>
 *
 +  <a>StartPipelineExecution</a>, which runs the the most recent revision of an artifact through the pipeline.
 *
 +  </li> <li>
 *
 +  <a>UpdatePipeline</a>, which updates a pipeline with edits or changes to the structure of the pipeline.
 *
 +  </li> </ul>
 *
 + Pipelines include <i>stages</i>, which are which are logical groupings of gates and actions. Each stage contains one or more actions that must complete before the next stage begins. A stage will result in success or failure. If a stage fails, then the pipeline stops at that stage and will remain stopped until either a new version of an artifact appears in the source location, or a user takes action to re-run the most recent artifact through the pipeline. You can call <a>GetPipelineState</a>, which displays the status of a pipeline, including the status of stages in the pipeline, or <a>GetPipeline</a>, which returns the entire structure of the pipeline, including the stages of that pipeline. For more information about the structure of stages and actions, also refer to the <a href="http://docs.aws.amazon.com/codepipeline/latest/userguide/pipeline-structure.html">AWS CodePipeline Pipeline Structure Reference</a>.
 *
 + Pipeline stages include <i>actions</i>, which are categorized into categories such as source or build actions performed within a stage of a pipeline. For example, you can use a source action to import artifacts into a pipeline from a source such as Amazon S3. Like stages, you do not work with actions directly in most cases, but you do define and interact with actions when working with pipeline operations such as <a>CreatePipeline</a> and <a>GetPipelineState</a>.
 *
 + Pipelines also include <i>transitions</i>, which allow the transition of artifacts from one stage to the next in a pipeline after the actions in one stage complete.
 *
 + You can work with transitions by calling:
 *
 +  <ul> <li>
 *
 +  <a>DisableStageTransition</a>, which prevents artifacts from transitioning to the next stage in a pipeline.
 *
 +  </li> <li>
 *
 +  <a>EnableStageTransition</a>, which enables transition of artifacts between stages in a pipeline.
 *
 +  </li> </ul>
 *
 +  <b>Using the API to integrate with AWS CodePipeline</b>
 *
 + For third-party integrators or developers who want to create their own integrations with AWS CodePipeline, the expected sequence varies from the standard API user. In order to integrate with AWS CodePipeline, developers will need to work with the following items:
 *
 +  <b>Jobs</b>, which are instances of an action. For example, a job for a source action might import a revision of an artifact from a source.
 *
 + You can work with jobs by calling:
 *
 +  <ul> <li>
 *
 +  <a>AcknowledgeJob</a>, which confirms whether a job worker has received the specified job,
 *
 +  </li> <li>
 *
 +  <a>GetJobDetails</a>, which returns the details of a job,
 *
 +  </li> <li>
 *
 +  <a>PollForJobs</a>, which determines whether there are any jobs to act upon,
 *
 +  </li> <li>
 *
 +  <a>PutJobFailureResult</a>, which provides details of a job failure, and
 *
 +  </li> <li>
 *
 +  <a>PutJobSuccessResult</a>, which provides details of a job success.
 *
 +  </li> </ul>
 *
 +  <b>Third party jobs</b>, which are instances of an action created by a partner action and integrated into AWS CodePipeline. Partner actions are created by members of the AWS Partner Network.
 *
 + You can work with third party jobs by calling:
 *
 +  <ul> <li>
 *
 +  <a>AcknowledgeThirdPartyJob</a>, which confirms whether a job worker has received the specified job,
 *
 +  </li> <li>
 *
 +  <a>GetThirdPartyJobDetails</a>, which requests the details of a job for a partner action,
 *
 +  </li> <li>
 *
 +  <a>PollForThirdPartyJobs</a>, which determines whether there are any jobs to act upon,
 *
 +  </li> <li>
 *
 +  <a>PutThirdPartyJobFailureResult</a>, which provides details of a job failure, and
 *
 +  </li> <li>
 *
 +  <a>PutThirdPartyJobSuccessResult</a>, which provides details of a job success.
 *
 +  </li> </ul>
 */

/**
 * @brief  Constructs a new CodePipelineClient object.
 *
 * @param  region       AWS region for this client to service requests for.
 * @param  credentials  AWS credentials to use for signing requests.
 * @param  manager      Network access manager for sending requests.
 * @param  parent       This object's parent.
 */
CodePipelineClient::CodePipelineClient(
    const AwsRegion::Region region,
    AwsAbstractCredentials * credentials,
    QNetworkAccessManager * const manager,
    QObject * const parent)
: AwsAbstractClient(new CodePipelineClientPrivate(this), parent)
{
    Q_D(CodePipelineClient);
    d->region = region;
    d->credentials = credentials;
    d->networkAccessManager = manager;
    d->serviceName = QLatin1String("{{servicename}}");
}

/**
 * @brief  Constructs a new CodePipelineClient object.
 *
 * This overload allows the caller to specify the specific endpoint to send
 * requests to.  Typically, it is easier to use the alternative constructor,
 * which allows the caller to specify an AWS region instead, in which case this
 * client will determine the correct endpoint for the given region
 * automatically (via AwsEndpoint::getEndpoint).
 *
 * @param  endpoint     Endpoint for building requests URLs.
 * @param  credentials  AWS credentials to use for signing requests.
 * @param  manager      Network access manager for sending requests.
 * @param  parent       This object's parent.
 *
 * @see  AwsEndpoint::getEndpoint
 */
CodePipelineClient::CodePipelineClient(
    const QUrl &endpoint,
    AwsAbstractCredentials * credentials,
    QNetworkAccessManager * const manager,
    QObject * const parent)
: AwsAbstractClient(new CodePipelineClientPrivate(this), parent)
{
    Q_D(CodePipelineClient);
    d->endpoint = endpoint;
    d->credentials = credentials;
    d->networkAccessManager = manager;
    d->serviceName = QLatin1String("{{servicename}}");
}

/// @todo {{publicSlots}}

/**
 * @internal
 *
 * @class  CodePipelineClientPrivate
 *
 * @brief  Private implementation for CodePipelineClient.
 */

/**
 * @internal
 *
 * @brief  Constructs a new CodePipelineClientPrivate object.
 *
 * @param  q  Pointer to this object's public CodePipelineClient instance.
 */
CodePipelineClientPrivate::CodePipelineClientPrivate(CodePipelineClient * const q)
    : AwsAbstractClientPrivate(q)
{
    signature = new AwsSignatureV4();
}

QTAWS_END_NAMESPACE