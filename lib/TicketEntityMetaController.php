<?php
/**
 * View can see this properties
 */
class TicketEntityMetaController extends EntityDefaultMetadataController {
  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['title'] = array(
      'label' => t('Title'),
      'description' => t('The ticket title.'),
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer ticket',
      'schema field' => 'title',
    );

    $properties['type'] = array(
      'type' => 'ticket',
      'getter callback' => 'entity_property_getter_method',
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer ticket',
      'required' => TRUE,
      'description' => t('The ticket type.'),
    ) + $properties['type'];

    unset($properties['uid']);

    $properties['user'] = array(
      'label' => t("User"),
      'type' => 'user',
      'description' => t("The owner of the ticket."),
      'getter callback' => 'entity_property_getter_method',
      'setter callback' => 'entity_property_setter_method',
      'setter permission' => 'administer ticket',
      'required' => TRUE,
      'schema field' => 'uid',
    );

    $properties['created'] = array(
      'label' => t("Date created"),
      'type' => 'date',
      'description' => t("The date the ticket was created."),
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer ticket',
      'schema field' => 'created',
    );
    $properties['changed'] = array(
      'label' => t("Date changed"),
      'type' => 'date',
      'schema field' => 'changed',
      'description' => t("The date the ticket was most recently updated."),
    );

    return $info;
  }
}